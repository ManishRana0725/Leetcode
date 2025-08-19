class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        unordered_map<int , int> x;
        unordered_map<int , int> y;
        int count = 0;
        for(int i=0 ; i<n ; i++){
            int no_ofX = 0 ;
            int no_ofY = 0;
            for(int j = 0 ; j<m ; j++){
                
                if(grid[i][j] == 'Y'){
                    no_ofY++;
                }
                if(grid[i][j] == 'X'){
                    no_ofX++;
                }

                y[j] = y[j]+no_ofY;
                x[j] = x[j]+no_ofX;


                if(y[j] == x[j] && x[j] > 0)count++;
            }
        }

        return count;

        
        
    }
};