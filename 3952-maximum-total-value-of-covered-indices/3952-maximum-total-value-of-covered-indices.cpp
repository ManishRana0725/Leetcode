class Solution {
public:
    long long dp[100001][2];

    long long solve(int i, vector<int>& nums, string& s, bool prev) {
        int n = s.size();

        if (i == n) return 0;

        if (dp[i][prev] != -1)
            return dp[i][prev];

        long long ans = 0;

        if (s[i] == '1') {

           
            ans = nums[i] + solve(i + 1, nums, s, true);

           
            if (i > 0 && !prev) {
                ans = max(
                    ans,
                    (long long)nums[i - 1] +
                    solve(i + 1, nums, s, false)
                );
            }

        } else {

            ans = solve(i + 1, nums, s, false);

        }

        return dp[i][prev] = ans;
    }

    long long maxTotal(vector<int>& nums, string s) {

        memset(dp, -1, sizeof(dp));

        return solve(0, nums, s, false);
    }
};