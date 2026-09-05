class Solution {
public:
    int dfs(int node , vector<int>& vis , vector<vector<int>>& adj){
        vis[node] = 1;
        int ans = 1;
        for(auto it : adj[node]){
            
            if(vis[it])continue;

            int next = dfs(it , vis , adj);
            ans += next;
        }
        return ans;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> adj(n);

        for(int i=0 ; i<n ;i++){
            for(int j = 0 ; j<n ; j++){

                if(i ==j)continue;

                int x1 = bombs[i][0];
                int y1 = bombs[i][1];
                int r1 = bombs[i][2];

                int x2 = bombs[j][0];
                int y2 = bombs[j][1];
                int r2 = bombs[j][2];

                long long dx = x1 - x2;
                long long dy = y1 - y2;

                long long distance = dx * dx + dy * dy;

                if(distance <= 1LL * r1 * r1) {
                    adj[i].push_back(j);
                }
            }   
        }

        
        int maxi = 1;
        for(int i=0 ; i<n ; i++){
            vector<int> vis(n , 0);
            maxi = max(maxi , dfs(i , vis , adj));
            
        }
        return maxi;
    }
};