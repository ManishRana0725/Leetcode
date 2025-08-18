class Solution {
public:
    bool check(int node , vector<vector<int>> & adj , vector<int>& col){
        queue<int> q;
        q.push(node);
        while(!q.empty()){
            int n = q.front();
            q.pop();

            for(auto it : adj[n]){
                if(col[it] == -1){
                    col[it] = !col[n];
                    q.push(it);
                }else if(col[it] == col[n]){
                    return false;
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n+1);
        for(auto it : dislikes){
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> col(n+1 , -1);

        for(int i= 1 ; i<n+1 ; i++){
            if(col[i] == -1){
                if(check(i , adj , col) == false){
                    return false;
                }
            }
        }
        return true;
    }
};