class Solution {
public:
    int ans = -1;
    void dfs(int node , vector<vector<int>> & adj , int currtime , vector<int>& vis , vector<int>& vistime){
        vis[node] = 1;
        vistime[node] = currtime;
        for(auto it : adj[node]){

            if(vis[it] == 1){
                ans = max(ans , (currtime - vistime[it]+1));
            }
            if(vis[it] == 0){
                dfs(it , adj , currtime+1 , vis , vistime);
            }

        }
        vis[node] = 2;
        return;
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();

        vector<vector<int>> adj(n);
        vector<int> vis(n , 0);

        vector<int> vistime(n , 0);
        for(int i=0 ; i<n ; i++){
            if(edges[i] != -1)
                adj[i].push_back(edges[i]);
        }

        for(int i=0 ; i<n ; i++){
            if(vis[i] == 0){
                dfs(i , adj , 1 , vis , vistime);
            }
        }

        return ans;
    }
};