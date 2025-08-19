class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i , int j , string& s){

        if(i >= j)return 0;

        if(dp[i][j] != -1)return dp[i][j];
        int res = INT_MAX;

        if(s[i] == s[j]){
            res = solve(i+1 , j-1 , s);
        }
        else{
            res = min(res , 1  + solve(i+1 , j , s)) ;
            res = min(res , 1 + solve(i , j-1 , s));
            

        }

        return dp[i][j] = res;
    }
    int minInsertions(string s) {
        int n = s.size();
        dp.resize(n+1 , vector<int> (n+1 , 0));
        //return solve(0 , n-1 , s);
        int res = INT_MAX;
        for(int i=n-1  ; i>=0 ; i--){
            for(int j=0 ; j<n ;j++){
                if(i >= j)continue;
               
                if(s[i] == s[j]){
                    dp[i][j] = dp[i+1][j-1];
                }
                else{
                    dp[i][j] =  min( 1  + dp[i+1][j] , 1 + dp[i][j-1]);
                  
                }

                
            }
        }
        return dp[0][n-1];
    }       
};