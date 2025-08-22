class Solution {
public:
    
    vector<int> dfs(int node , int parent , vector<vector<int>>& adj , vector<int>& ans , string& labels){
        vector<int> freq(26 , 0);
        for(auto it : adj[node]){
            if(it != parent){
                vector<int> child = dfs(it , node , adj , ans , labels);
                for(int i=0 ; i<26 ; i++){
                    freq[i] += child[i];
                }
            }
        }
        freq[labels[node]-'a']++;

        ans[node] = freq[labels[node]-'a'];

        return freq;

    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adj(n);
        vector<int> ans(n , 0);
        
        for(auto it : edges){
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);

        }

        vector<int> v =  dfs(0 , -1 , adj , ans , labels);
        return ans;
    }
};