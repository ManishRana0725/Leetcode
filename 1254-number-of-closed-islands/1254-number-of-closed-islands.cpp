class Solution {
public:
    
    bool dfs(int i , int j , vector<vector<int>>& grid , vector<vector<bool>>& vis){
        vis[i][j] = true;
        int n = grid.size();
        int m = grid[0].size();

        bool ans = true;
        if(i == 0 || i == n-1 || j == 0 || j == m-1){
            ans =  false;
        }

        int dx[4] = {0 , 1 , 0 , -1};
        int dy[4] = {1 , 0 , -1 , 0};

        for(int k = 0 ; k<4 ; k++){
            int newx = i + dx[k];
            int newy = j + dy[k];

            if(newx >= 0 && newx <= n-1 && newy >= 0 && newy <= m-1 && grid[newx][newy] == 0 && !vis[newx][newy]){
                bool temp = dfs(newx , newy , grid , vis);
                if(!temp)ans= false;
            }
        }

        return ans;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int count = 0;
        vector<vector<bool>> vis(n , vector<bool>(m , false));
        for(int i = 0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                
                if(grid[i][j] == 0 && !vis[i][j]){
                    bool ans = dfs(i , j , grid , vis);

                    if(ans)count++;
                }

            }
        }
        return count;
    }
};