class Solution {
public:
    int x[4] = {0 , 1 , 0 , -1};
    int y[4] = {1 , 0 , -1 , 0};
    long long dfs(int i , int j , vector<vector<int>>& grid, vector<vector<int>>& vis){
        int n = grid.size();
        int m = grid[0].size();
        vis[i][j] = 1;
        long long ans = 0;
        for(int k=0;k<4;k++){
            int newx = i + x[k];
            int newy = j + y[k];

            if(newx >= 0 && newy >= 0 && newx < n && newy < m && grid[newx][newy] > 0 && !vis[newx][newy]){
                ans += dfs(newx , newy , grid , vis);
            }
        }
        return ans += grid[i][j];
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        
        vector<vector<int>> vis (n , vector<int>(m , 0));
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                long long sum = 0;
                if( grid[i][j] > 0 && !vis[i][j] ){
                    sum = dfs(i , j , grid , vis);
                    if(sum % k == 0){
                        ans++;
                    }
                    
                }
            }
        }
        return ans;
    }
};