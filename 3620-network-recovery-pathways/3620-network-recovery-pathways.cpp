class Solution {
public:
    bool solve(int minEdge, vector<vector<pair<int, int>>> &adj, 
                  vector<bool> &online, long long k, int n) {
        // {cost till now, node}
        
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        vector<long long> dist(n, LLONG_MAX);
    
        pq.push({0, 0});
        dist[0] = 0;
    
       while (!pq.empty()) {
            auto [cost, node] = pq.top();
            pq.pop();

            if (cost != dist[node]) continue;

            if (node == n - 1) return true;

            for (auto &[nei, edgeCost] : adj[node]) {
                if (nei != n - 1 && !online[nei]) continue;
                if (edgeCost < minEdge) continue;

                long long newCost = cost + edgeCost;

                if (newCost < dist[nei] && newCost <= k) {
                    dist[nei] = newCost;
                    pq.push({newCost, nei});
                }
            }
        }
    
        return false;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int, int>>> adj(n);
        int low = 0, high = 0;
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int cost = e[2];
            adj[u].emplace_back(v , cost);
            high = max(high, cost);
        }
    
        int ans = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (solve(mid, adj, online, k, n)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    
        return ans;
    }
};