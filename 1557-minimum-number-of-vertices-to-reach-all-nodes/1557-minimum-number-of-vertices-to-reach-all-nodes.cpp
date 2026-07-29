class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(n);
        vector<int> Indegree(n , 0);
        for(auto it : edges){
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            Indegree[v]++;
        }

        vector<int> ans;

        for(int i=0 ; i<n ; i++){
            if(Indegree[i] == 0){
                ans.push_back(i);
            }
        }

        return ans;
    }
};