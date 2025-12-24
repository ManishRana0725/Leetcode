class Solution {
public:
    int ans = 0;
    void dfs(int node , vector<vector<pair<int , int>>> & adj , vector<int>& vis , int parent ){

        vis[node] = 1;
        for(auto it : adj[node]){
            int v = it.first;
            int real = it.second;

            if(parent == v)continue;

            if(real == 1){
                ans++;
                dfs(v , adj , vis , node);
            }else{
                dfs(v , adj , vis , node );
            }
        }

        return;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        
        vector<vector<pair<int , int>>> adj(n);

        for(auto it : connections){
            int u = it[0];
            int v = it[1];

            adj[u].push_back({v , 1});
            adj[v].push_back({u , 0});
        }


        vector<int> vis(n , 0);

        dfs(0 , adj , vis , -1);

        return ans;

    }
};