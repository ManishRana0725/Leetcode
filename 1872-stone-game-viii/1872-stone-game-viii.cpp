class Solution {
public:
    vector<int> dp;
    int solve(int i , vector<int>& prefix ){
        int n = prefix.size();

        if(i == n-1) return prefix[n-1];

        if(dp[i] != -1)return dp[i];

        int skip = solve(i+1 , prefix );

        int take = prefix[i] - solve(i+1 , prefix );

        return dp[i] = max(skip , take);

    }
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        dp.resize(n, 0);
        vector<int> prefix(n);
        prefix[0] = stones[0];

        for(int i=1 ; i<n ; i++){
            prefix[i] = prefix[i-1] + stones[i];
        }

        //return solve(1 , prefix );

        dp[n-1] = prefix[n-1];
        for(int i=n-2 ; i >= 1 ; i--){

            int skip = dp[i+1];

            int take = prefix[i] - dp[i+1];

            dp[i] = max(skip , take);
        }

        return dp[1];
    }
};