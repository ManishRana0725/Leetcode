class Solution {
public:
    vector<int> v;   
    vector<long long> dp;     

    long long solve(int i) {
        int n = v.size() - 1; 
        
        if (i == n) return 0;          
        if (dp[i] != -1) return dp[i];

        long long res = LLONG_MAX;
        for (int step = 1; step <= 3; step++) {
            int j = i + step;
            if (j <= n) {
                long long cost = v[j] + 1LL * (j - i) * (j - i);
                res = min(res, cost + solve(j));
            }
        }
        return dp[i] = res;
    }
    int climbStairs(int n, vector<int>& costs) {
        v = vector<int>(n + 1);
        v[0] = 0;
        for (int i = 1; i <= n; i++) {
            v[i] = costs[i - 1];
        }

        dp.assign(n + 1, -1);
        return (int)solve(0);
    }
};