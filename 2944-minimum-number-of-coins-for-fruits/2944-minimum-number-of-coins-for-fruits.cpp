class Solution {
public:
    int dp[1001];
    int solve(int i, vector<int>& prices){
        int n = prices.size();

        if(i >= n) return 0;

        if(dp[i] != -1) return dp[i];

        int ans = INT_MAX;

        for(int j = i+1; j <= min(n, i+i+2); j++){
            ans = min(ans, prices[i] + solve(j, prices));
        }

        return dp[i] = ans;
    }
    int minimumCoins(vector<int>& prices) {
        int n = prices.size();
        memset(dp , -1 , sizeof(dp));
        return solve(0 , prices);
    }
};