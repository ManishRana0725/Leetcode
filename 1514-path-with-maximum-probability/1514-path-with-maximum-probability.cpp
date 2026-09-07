class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        
        vector<vector<pair<int , double>>> adj(n);
        int i=0;
        for(auto it : edges){
            adj[it[0]].push_back({it[1] , succProb[i]});
            adj[it[1]].push_back({it[0] , succProb[i]});
            i++;
        }

        priority_queue<pair<double , int>> pq;
        vector<double> dist(n , 0.0);
        dist[start_node] = 1.0;
        pq.push({1.0 , start_node});

        while(!pq.empty()){
            auto [cost , node] = pq.top();
            pq.pop();

            if(node == end_node){
                return cost;
            }

            for(auto it : adj[node]){
                int newnode = it.first;
                double nodecost = it.second;
                double totalCost = cost * nodecost;

                if(dist[newnode] < totalCost){
                    dist[newnode] = totalCost;
                    pq.push({totalCost , newnode});
                }
            }
        }
        return 0.0;
    }
};