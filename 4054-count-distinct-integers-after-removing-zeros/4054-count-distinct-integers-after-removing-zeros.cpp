class Solution {
public:
    string s ;
    long long dp[17][2][2];
    long long solve(int i , bool tight , bool started ){
        
        if(i == s.size()){
            return started;
        }

        if(dp[i][tight][started] != -1)return dp[i][tight][started];

        
        long long ans = 0;
        
        int limit = tight ? (s[i]-'0') : 9 ;
        for(int d = 0; d <= limit ; d++){
            // tight will only be true if it already is or if d == s[i];
            if(d == 0){
                if(!started){
                    ans += solve(i+1 , tight && (d == limit) , false);
                }else{
                    // do nothing
                }
            }else{
                ans += solve(i+1 , tight && (d == limit) , true);
            }
        }
     
        return dp[i][tight][started] = ans;
    }
    long long countDistinct(long long n) {
        s = to_string(n);

        memset(dp , -1 , sizeof(dp));

        return solve(0 , 1 , 0);
    }
};