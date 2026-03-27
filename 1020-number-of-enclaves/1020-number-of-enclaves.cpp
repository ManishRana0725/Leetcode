class Solution {
public:
    void dfs(int row , int col ,vector<vector<int>>& board , vector<int>& rowd , 
            vector<int>& cold , vector<vector<int>>& vis)
    {
        int n = board.size();
        int m = board[0].size();
        vis[row][col] = 1;
        for(int i=0;i<4;i++){
            int nrow = row+rowd[i];
            int ncol = col+cold[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && board[nrow][ncol] == 1 && !vis[nrow][ncol]){
                
                dfs(nrow , ncol , board , rowd , cold , vis);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int>rdir = {-1 , 0 ,+1 ,0};
        vector<int>cdir = {0 , 1 , 0 , -1};
        vector<vector<int>> vis(n, vector<int>(m,0));
        

        for(int j =0;j<m;j++){
            if(grid[0][j] == 1 && !vis[0][j]){
                dfs(0 , j , grid  , rdir, cdir , vis);
            }

            if(grid[n-1][j] == 1 && !vis[n-1][j]){
                dfs(n-1 , j , grid , rdir, cdir , vis);
            }
        }

        for(int i=0;i<n;i++){
            if(grid[i][0] == 1 && !vis[i][0]){
                dfs(i , 0 , grid , rdir, cdir , vis);
            }

            if(grid[i][m-1] == 1 && !vis[i][m-1]){
                dfs(i , m-1 , grid , rdir, cdir , vis);
            }
        }

        int cnt =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};