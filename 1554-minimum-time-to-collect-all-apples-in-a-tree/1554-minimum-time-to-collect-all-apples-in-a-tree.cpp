class Solution {
public:
    int dfs(int node , int parent , vector<vector<int>>& adj , vector<bool>& hasApple){
        int time = 0;

        for(auto it : adj[node]){
            if(it == parent)continue;
            int childtime = dfs(it , node , adj , hasApple);


            if(childtime > 0 || hasApple[it]){
                time += childtime + 2;
            }
        }
        return time;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        
        for(auto it : edges){
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        
        
        return dfs(0 , -1 , adj , hasApple);
    }
};