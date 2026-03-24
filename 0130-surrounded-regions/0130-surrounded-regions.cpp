class Solution {
public:
     void dfs(int row , int col ,vector<vector<char>>& board , vector<int>& rowd , 
            vector<int>& cold , vector<vector<int>>& vis)
    {
        int n = board.size();
        int m = board[0].size();
        vis[row][col] = 1;
        for(int i=0;i<4;i++){
            int nrow = row+rowd[i];
            int ncol = col+cold[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && board[nrow][ncol] == 'O' && !vis[nrow][ncol]){
                
                dfs(nrow , ncol , board , rowd , cold , vis);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<int>rdir = {-1 , 0 ,+1 ,0};
        vector<int>cdir = {0 , 1 , 0 , -1};
        vector<vector<int>> vis(n, vector<int>(m,0));
        

        for(int j =0;j<m;j++){
            if(board[0][j] == 'O' && !vis[0][j]){
                dfs(0 , j , board  , rdir, cdir , vis);
            }

            if(board[n-1][j] == 'O' && !vis[n-1][j]){
                dfs(n-1 , j , board , rdir, cdir , vis);
            }
        }

        for(int i=0;i<n;i++){
            if(board[i][0] == 'O' && !vis[i][0]){
                dfs(i , 0 , board , rdir, cdir , vis);
            }

            if(board[i][m-1] == 'O' && !vis[i][m-1]){
                dfs(i , m-1 , board , rdir, cdir , vis);
            }
        }


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == 'O' && !vis[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
        
    }
};