class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n);
        vector<vector<pair<int, int>>> incoming(n);
        
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({v, w});
            incoming[v].push_back({u, w});
        }
        
        
        priority_queue<tuple<int, int>, 
                      vector<tuple<int, int>>, 
                      greater<tuple<int, int>>> pq;
        
        // visited[node][canUseSwitch] = minimum cost
        vector<int> dist(n , INT_MAX);
        vector<int> vis(n , 0);
        vector<int> rever(n , 0);
        pq.push({0, 0});
        dist[0] = 0;
        
        
        while (!pq.empty()) {
            auto [cost, node] = pq.top();
            pq.pop();
            
            if (node == n - 1) return cost;
            
            
            if (cost > dist[node]) continue;
            if(vis[node])continue;

            vis[node] = 1;
            for (auto& [nextNode, edgeCost] : adj[node]) {
                int newCost = cost + edgeCost;
                if (newCost < dist[nextNode]) {
                    dist[nextNode] = newCost;
                    pq.push({newCost, nextNode});
                }
            }
            
            
            if (!rever[node] && !incoming[node].empty()) {
                rever[node] = 1;
                for (auto& [prevNode, reverseCost] : incoming[node]) {
                    int newCost = cost + (reverseCost * 2);
                    
                    if (newCost < dist[prevNode]) {
                        dist[prevNode] = newCost;
                        pq.push({newCost, prevNode});
                    }
                }
            }
        }
        
        return -1;
    }
};