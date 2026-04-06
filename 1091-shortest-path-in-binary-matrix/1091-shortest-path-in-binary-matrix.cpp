class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> distance ( n , vector<int>( n , 1e9) );
        distance[0][0] = 0;
        if(n == 1 && grid[0][0] == 1)return -1;
        if(n == 1 && grid[0][0] == 0)return 1;
        if(grid[0][0] == 1)return -1;
        
        queue<pair< int , pair<int , int>>> q;
        q.push({0 , { 0,0}});
        int dx[] = {-1 , -1 , 0 , 1 , 1 , 1 , 0 , -1};
        int dy[] = { 0 , 1 , 1 , 1 , 0 , -1 , -1 , -1};
        while(!q.empty()){
            int level = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();
            for(int i=0;i<8 ;i++){
                
                int dr = dx[i] + x ;
                int dc = dy[i] + y;
                if(dr >= 0 && dr < n && dc >= 0 && dc < n && grid[dr][dc] == 0 && distance[dr][dc] > level+1){
                    distance[dr][dc] = level+1;
                    q.push({level+1 , {dr , dc}});
                    if(dr == n-1 && dc == n-1){
                        return distance[dr][dc]+1;
                    }
                }    
            }
        }
        return -1;
    }
};