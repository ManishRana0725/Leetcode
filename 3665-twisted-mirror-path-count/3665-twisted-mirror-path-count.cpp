class Solution {
public:
    const int M = 1000000000+7;
    vector<vector<vector<int>>> dp;
    int solve(int i , int j , int prev ,  vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();

        if(i >= n || j >= m)return 0;

        if(i == n-1 && j == m-1)return 1;

        if(dp[i][j][prev] != -1)return dp[i][j][prev];
        int take = 0;
        if(grid[i][j] == 1){
            if(prev == 1){
                take =  (take + solve(i+1 , j , 2 , grid))%M;
            }else if(prev == 2){
                take = (take + solve(i , j+1 , 1 , grid))%M;
            }
        }
        else{
            take = (take + solve(i+1 , j , 2 , grid ))%M;
            take = (take + solve(i , j+1 , 1 , grid))%M;
        }
        return dp[i][j][prev] = take;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        dp.resize(n+1 , vector<vector<int>> ( m+1 , vector<int>(3 , -1)));
        return solve(0 , 0 , 0 , grid);
    }
};