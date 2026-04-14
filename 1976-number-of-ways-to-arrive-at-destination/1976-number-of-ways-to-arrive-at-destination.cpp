class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod = 1e9+7;
        vector<vector<pair<long long , long long >>> adj(n);
        for(auto it : roads){
            adj[it[0]].push_back({it[1] , it[2]});
            adj[it[1]].push_back({it[0] , it[2]});
        }
        // < time , dest >
        
        vector<long long> dist( n , 1e18) , ways(n , 0);
        dist[0] = 0;
        ways[0] = 1;
        priority_queue<pair<long long , long long> , vector<pair<long long , long long>>
                 , greater<pair<long long , long long>>> pq;
        pq.push({0 , 0});
        while(!pq.empty()){
            long long time = pq.top().first;
            long long node = pq.top().second;
            
            pq.pop();
            for(auto it : adj[node]){
                long long adjnode = it.first;
                long long egw = it.second ;
                if(dist[adjnode] > egw + time){
                    dist[adjnode] = egw + time;
                    pq.push({dist[adjnode] , adjnode});
                    ways[adjnode] = ways[node];
                }
                else if(dist[adjnode] == egw + time){
                    ways[adjnode] += ways[node];
                    ways[adjnode] = ways[adjnode] % mod;
                }
                
            }
        }
        return ways[n-1] % mod;
    }
};