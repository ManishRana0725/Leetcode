class Solution {
public:
    int solve(int r1, int r2, int c1, int c2, 
              vector<int>& horizontalCut, vector<int>& verticalCut,
              vector<vector<vector<vector<int>>>>& dp) {
        
        
        if (r1 == r2 && c1 == c2) return 0;
        
        
        if (dp[r1][r2][c1][c2] != -1) return dp[r1][r2][c1][c2];
        
        int result = INT_MAX;
        
        
        for (int k = r1; k < r2; k++) {
            int cost = horizontalCut[k] + 
                      solve(r1, k, c1, c2, horizontalCut, verticalCut, dp) +
                      solve(k+1, r2, c1, c2, horizontalCut, verticalCut, dp);
            result = min(result, cost);
        }
        
        
        for (int k = c1; k < c2; k++) {
            int cost = verticalCut[k] + 
                      solve(r1, r2, c1, k, horizontalCut, verticalCut, dp) +
                      solve(r1, r2, k+1, c2, horizontalCut, verticalCut, dp);
            result = min(result, cost);
        }
        
        return dp[r1][r2][c1][c2] = result;
    }
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
      
        vector<vector<vector<vector<int>>>> dp(m, vector<vector<vector<int>>>(m, 
            vector<vector<int>>(n, vector<int>(n, -1))));
        
        return solve(0, m-1, 0, n-1, horizontalCut, verticalCut, dp);
    }
};