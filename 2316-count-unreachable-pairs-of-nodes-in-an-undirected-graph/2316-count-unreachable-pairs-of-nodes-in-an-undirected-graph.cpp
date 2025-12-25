class Solution {
public:

    int dfs(int node , vector<vector<int>> & adj , int parent , vector<int>& vis){

        vis[node] = 1;
        int count = 1;
        for(auto it : adj[node]){
            if(it == parent )continue;
            if(!vis[it]){
                count += dfs(it , adj , node , vis);
            }
        }

        return count;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(n);

        for(auto it : edges){
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n , 0);
        long long ans = 0;
        int visnode = 0;
        for(int i=0 ; i<n ; i++){
            if(!vis[i]){
                int count = dfs(i , adj , -1 , vis);
                ans += 1LL * visnode * count;
                visnode += count;
            }
        }
        return ans;
    }
};