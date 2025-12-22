class Solution {
public:
    void dfs(int node , vector<vector<int>>& adj , vector<int>& vis , int dis , vector<int>& distance){
        vis[node] = true;
        distance[node] = dis;

        for(auto it : adj[node]){

            if(!vis[it])
                dfs(it , adj , vis , dis+1 , distance);
        }

        return ;
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        
        int n = edges.size();

        vector<int> vis1(n , 0) , vis2(n , 0);
        vector<int> dist1(n , -1) , dist2(n , -1);

        vector<vector<int>> adj(n );

        for(int i=0 ; i<n ; i++){

            if(edges[i] != -1)
                adj[i].push_back(edges[i]);
        }
        // dfs for node 1

        dfs(node1 , adj , vis1 , 0 , dist1);

        dfs(node2 , adj , vis2 , 0 , dist2);



        int mini = INT_MAX;
        int ans = -1;
        for(int i=0 ; i < n ; i++){
            if(vis1[i] && vis2[i]){
                int d1 = dist1[i];
                int d2 = dist2[i];
                int d = max(d1 , d2);
                
                if(d < mini){
                    mini = d;
                    ans = i;
                }

            }
        }
        return ans;
    }
};