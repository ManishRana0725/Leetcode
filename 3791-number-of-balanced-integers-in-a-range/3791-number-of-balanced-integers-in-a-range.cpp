class Solution {
public:
//     long long even = 0;
//     long long odd = 0;
//     long long dp[17][2][2][2][300];
// // maintain a variable called started if started is true then we are equal to or lower than 
//     long long solve(int i , bool lowtight , bool hightight , bool started , string& low , string& high  , int diff){
//         int n = high.size();
//         if(i == n){
//             if(started && diff == 0){
//                 return 1;
//             }else{
//                 return 0;
//             }
//         }

//         if(dp[i][lowtight][hightight][started][diff + 135] != -1)return dp[i][lowtight][hightight][started][diff+135];
//         long long ans = 0;
//         int lo = lowtight ? low[i] - '0' : 0;
//         int hi = hightight ? high[i] - '0' : 9;
//         for(int d = lo ; d <= hi ; d++){
//             int newDiff = diff;
//             if(i%2 == 0){
//                 newDiff += d;
//             }else{
//                 newDiff -= d;
//             }
//             bool  newstarted  = started || (d != 0);

//             ans += solve(i+1 , lowtight && (d == lo) , hightight && (d == hi) , newstarted , low , high , newDiff);
                
            
//         }


//         return dp[i][lowtight][hightight][started][diff+135] = ans;
        
//     }
    long long dp[17][2][2][300];
    long long solve(int i , bool tight , bool started , int diff , string& s){

        int n = s.size();
        if(i == n){
            if(started && diff == 0){
                return 1;
            }else{
                return 0;
            }
        }

        if(dp[i][tight][started][diff+135] != -1)return dp[i][tight][started][diff+135] ;

        int last = tight ? (s[i]-'0') : 9;
        long long ans = 0;
        
        for(int d = 0 ; d <= last; d++){

            bool newstarted = started || (d != 0);
            int newdiff = diff;
            if(i%2 == 0){
                newdiff += d;
            }else{
                newdiff -= d;
            }
            ans += solve(i+1 , tight && (d == last) , newstarted , newdiff , s );
        }

        return dp[i][tight][started][diff+135] = ans;
    }
    long long countBalanced(long long l, long long h) {
        memset(dp, -1, sizeof(dp));
        string low = to_string(l-1);
        string high = to_string(h);

        long long ans1 = solve(0 , 1 , 0 , 0 , high);
        memset(dp, -1, sizeof(dp));
        long long ans2 = solve(0 , 1 , 0 , 0 , low);

        return (ans1 - ans2);
    
    }
};