class Solution {
public:
    // dp[node][1] -> parent or grandparents or grand .. node values is  taken so for this subtree all values not taken
    // dp[node][0] -> parent or grandparents or grand .. node value is not taken so can take for this node or continue;
    long long solve(int node , int par ,bool flag , vector<vector<int>>& adj , vector<int>& values , vector<vector<long long>>& dp ){
        
        bool leaf = true;
            

        for(auto child : adj[node]){
            if(child == par) continue;
            leaf = false;
        }

        if(leaf){
            if(flag)return values[node];
            else{
                return 0;
            }
        }
    
        
        if(dp[node][flag] != -1)return dp[node][flag];
        
        long long ans = 0;
        if(flag == true){
            ans = values[node];
            for(auto it : adj[node]){
                if(it == par)continue;
                ans += solve(it , node ,flag , adj , values , dp);
            }
        }
        long long ans1 = 0 , ans2 = 0;
        if(flag == false){
             // leaving the node values 
            for(auto it : adj[node]){
                if(it == par)continue;
                ans1 += solve(it , node , true , adj , values , dp);
            }
            ans2 = values[node]; // taking the node value and child tree will leav
            for(auto it : adj[node]){
                if(it == par)continue;
                ans2 += solve(it , node ,false , adj , values , dp);
            }

            
        }
        ans = max(ans , max(ans1 , ans2));
        return dp[node][flag] = ans;
    
    }
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        int n = values.size();

        vector<vector<int>> adj(n);

        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<vector<long long>> dp(n , vector<long long>(2 , -1));

        return solve(0 , -1 , false , adj , values , dp);
        
    }
};

