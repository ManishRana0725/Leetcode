class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        set<int> x , y;
        int n = grid.size();
        int m = grid[0].size();
        int x_min = INT_MAX;
        int x_max = INT_MIN;
        int y_min = INT_MAX;
        int y_max = INT_MIN;
        for(int i=0 ;i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(grid[i][j] == 1){
                    x.insert(i);
                    y.insert(j);
                    x_min = min(x_min , i);
                    x_max = max(x_max , i);
                    y_min = min(y_min , j);
                    y_max = max(y_max , j);
                    
                }
            }
        }

        return ((x_max - x_min)+1) * ((y_max - y_min)+1);
    }
};