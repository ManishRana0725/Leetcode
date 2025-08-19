class Solution {
public:
    vector<vector<int>> ans;
    void solve(int node , vector<vector<int>> &adj , vector<int>& res ){
        int n = adj.size();
        if(node == n-1){
            ans.push_back(res);
            return;
        }

        for(auto it : adj[node]){
            res.push_back(it);
            solve(it , adj , res);
            res.pop_back();
        }

    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> res ;
        res.push_back(0);
        solve(0 , graph , res);
        return ans;

    }
};