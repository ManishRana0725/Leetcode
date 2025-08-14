class Solution {
public:
    const int M = 1000000007;
    vector<vector<int>>dp;
    vector<vector<int>> mpp;
    int solve(int i , int startind , vector<string>& words, string& target){
        int n = target.size();
        int m = words.size();
        int z = words[0].size();

        if(i == n)return 1;

        if(startind >= z)return 0;

        if(dp[i][startind] != -1)return dp[i][startind];

        int res = solve(i , startind+1 , words , target);

        if(mpp[startind][target[i]-'a'] > 0){
                
            res = (res +( 1LL * mpp[startind][target[i]-'a'] *  solve(i+1 , startind+1 , words , target))%M)%M;
        }
        return dp[i][startind] = res;
    }
    int numWays(vector<string>& words, string target) {
        int n = target.size();
        int m = words.size();
        int z = words[0].size();

        mpp.resize(z+1 , vector<int>(26 , 0));
        for(int i=0 ;i<z ; i++){
            for(int j=0 ; j<m ; j++){
                mpp[i][words[j][i]-'a']++;
            }
        }
        dp.resize(n+2 , vector<int>(z+2 , 0));
        // return solve(0 , 0 , words , target);



        // bc
        for(int i=0 ;i<z+1 ;i++){
            dp[n][i] = 1;
        }


        for(int i=n-1 ;i>=0 ; i--){
            for(int j=z-1;j>=0 ;j--){
                
                int res = dp[i][j+1];

                if(mpp[j][target[i]-'a'] > 0){
                        
                    res = (res +( 1LL * mpp[j][target[i]-'a'] *  dp[i+1][j+1])%M)%M;
                }

                dp[i][j] = res;
            }
        }
        return dp[0][0];
    }
};