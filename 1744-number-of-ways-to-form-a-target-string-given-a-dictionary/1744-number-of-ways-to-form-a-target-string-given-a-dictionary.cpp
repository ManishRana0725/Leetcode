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
        dp.resize(n+1 , vector<int>(z+1 , -1));
        return solve(0 , 0 , words , target);
    }
};