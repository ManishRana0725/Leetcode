class Solution {
public:
    vector<vector<int>> adj;
    vector<int> res;
    vector<int> child;

    void dfs(int node , int parent , int depth){

        res[0] += depth;
        child[node] = 1;
        for(auto it : adj[node]){
            if(parent != it){
                dfs(it , node , depth+1);
                child[node] += child[it];
            }
        }
        
    }
  
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
       adj.resize(n , {});

        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        res.resize(n , 0);
        child.resize(n , 0);
        dfs(0 , -1 , 0);


        queue<pair<int,int>> q;
        q.push({0, -1});

        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for(auto nei : adj[node]){
                if(nei == parent) continue;

                
                res[nei] = res[node] - child[nei] + (n - child[nei]);

                q.push({nei, node});
            }
        }

        return res;
    }
};