class Solution {
public:
    int n, m;

    vector<vector<vector<int>>> dp;

    int solve(int i, int j, int xr, vector<vector<int>>& grid) {
        xr ^= grid[i][j];

        // base case
        if (i == n - 1 && j == m - 1) {
            return xr;
        }

        if(dp[i][j][xr] != -1)return dp[i][j][xr];

        int ans = INT_MAX;

        // move right
        if (j + 1 < m) {
            ans = min(ans, solve(i, j + 1, xr, grid));
        }

        // move down
        if (i + 1 < n) {
            ans = min(ans, solve(i + 1, j, xr, grid));
        }

        return dp[i][j][xr] = ans;
    }

    int minCost(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        dp.resize(n, vector<vector<int>>(m , vector<int>(1024 , -1))) ;

        return solve(0, 0, 0, grid);
    }
};