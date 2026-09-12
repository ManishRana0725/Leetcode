class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        
        if(roads.size() == 0)return 0;
        vector<vector<int>> adj(n);
        vector<vector<bool>> path(n , vector<bool> (n , false));
        for(auto it : roads){
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
            path[u][v] = true;
            path[v][u] = true;
        }

        int ans = 1;
        for(int i=0 ; i<n ; i++){
            for(int j = i+1 ; j<n ; j++){

                int sum = adj[i].size() + adj[j].size();

                if(path[i][j]){
                    sum -= 1;
                }

                ans = max(ans , sum);
            }   
        }
        return ans;
    }
};