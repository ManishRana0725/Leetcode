class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        unordered_map<int , int> col , row;

        for(int i=0 ; i<n ; i++){
            for(int j =0 ; j<m ; j++){
                if(grid[i][j] == 1){
                    col[j]++;
                    row[i]++;
                }
               
            }
        }
        long long result = 0;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(grid[i][j] == 1 && row[i] > 1 && col[j] > 1){
                    long long times = (row[i]-1) * (col[j]-1) ; 
                    result += times;
                }
            }
        }
        return result;
    }
};
