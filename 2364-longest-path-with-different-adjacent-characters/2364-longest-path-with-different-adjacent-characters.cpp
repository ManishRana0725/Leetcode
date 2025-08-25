class Solution {
public:
    int ans = 1;

    int dfs(int node, vector<vector<int>>& adj, string& s, int parent) {
        int best1 = 0, best2 = 0; 

        for (auto child : adj[node]) {
            if (child == parent) continue;

            int len = dfs(child, adj, s, node);

            if (s[child] != s[node]) {
                if (len > best1) {
                    best2 = best1;
                    best1 = len;
                } else if (len > best2) {
                    best2 = len;
                }
            }
        }

       
        ans = max(ans, best1 + best2 + 1);

        return best1 + 1; 
    }

    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
            adj[i].push_back(parent[i]);
        }

        dfs(0, adj, s, -1);
        return ans;
    }
};
