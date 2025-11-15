class Solution {
public:
    vector<vector<vector<int>>> dp;
    int solve(int i , int j , int cost , vector<vector<int>>& grid, int k){
        int n = grid.size();
        int m = grid[0].size();

        if(cost > k)return INT_MIN;
        if(i == n-1 && j == m-1 ){
            
            if(grid[i][j] == 0){
                return 0;
            }
            if(grid[i][j]==1 && cost < k){
                return 1;
            }
            if(grid[i][j] == 2 && cost < k)return 2;
            else{
                return INT_MIN;
            }
            
        }

        if(dp[i][j][cost] != -1 )return dp[i][j][cost];
        int cost1 = 0;
        int res = INT_MIN;
        if(grid[i][j] > 0)cost1 =1 ;
        if(i < n-1 ){
            res = grid[i][j]+solve(i+1 , j , cost+cost1 , grid , k);
        }

        if( j < m-1){
            res = max(res , grid[i][j]+solve(i , j+1 , cost + cost1 , grid , k));
        }
        

        return dp[i][j][cost] = res;
        
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        dp.resize( n+1 , vector<vector<int>>(m+1 , vector<int>( k+1 , -1)));
        int ans = solve(0 , 0 , 0 , grid , k);
        if(ans < 0)return -1;
        return ans;
    }
};