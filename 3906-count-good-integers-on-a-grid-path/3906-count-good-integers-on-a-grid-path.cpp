class Solution {
public:
    vector<int> path;

    long long dp[17][2][8][11];

    long long solve(int i, int tight, int k, int prev, string &s) {
        if (i == 16) return 1;

        if (dp[i][tight][k][prev] != -1) return dp[i][tight][k][prev];

        int limit = tight ? s[i] - '0' : 9;
        long long ans = 0;

        for (int d = 0; d <= limit; d++) {
            int ntight = tight && (d == limit);

            if (k < 7 && i == path[k]) {
                if (d < prev) continue;
                ans += solve(i + 1, ntight, k + 1, d, s);
            } else {
                ans += solve(i + 1, ntight, k, prev, s);
            }
        }

        return dp[i][tight][k][prev] = ans;
    }

    long long count(long long x) {
        string s = to_string(x);
        while (s.size() < 16) s = '0' + s;

        memset(dp, -1, sizeof(dp));
        return solve(0, 1, 0, 0, s);
    }

    long long countGoodIntegersOnPath(long long l, long long r, string directions) {

        int x = 0, y = 0;
        path.push_back(0); 

        for (char c : directions) {
            if (c == 'D') x++;
            else y++;
            path.push_back(x * 4 + y);
        }

        return count(r) - count(l - 1);
    }
};