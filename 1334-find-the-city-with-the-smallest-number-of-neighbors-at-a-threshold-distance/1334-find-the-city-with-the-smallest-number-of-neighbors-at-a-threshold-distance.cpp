class Solution {
    public:
    void shortestdistance( int n , unordered_map<int , vector<pair<int , int>>>& adj , vector<int>& result ,int src){
        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int,int>>> pq;
        // { dist , node}
        result[src] = 0;
        fill(result.begin() , result.end() ,INT_MAX);
        pq.push({ 0 , src});
        while(!pq.empty()){
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it :adj[node]){
                int neg = it.first;
                int wt = it.second;
                if(result[neg] > wt + d){
                    result[neg] = wt + d;
                    pq.push({result[neg], neg});
                }       
            }
        }
    }

    
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        
        unordered_map<int , vector<pair<int , int>>>adj;
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v , wt});
            adj[v].push_back({u , wt});
        }
        
        vector<vector<int>> dist( n, vector<int>(n ,1e9+7));
        for(int i=0;i<n;i++){dist[i][i] = 0;}

        for(int i=0;i<n;i++){
            shortestdistance(n , adj , dist[i] , i);
            
           
        }
        // checking the negih if they have distance <= thresholddistacne
        int resultcity = -1;
        int leastreachCount = INT_MAX;
        for(int i=0;i<n;i++){
            int count = 0;
            for(int j=0;j<n;j++){
                if( i!=j &&dist[i][j] <= distanceThreshold){
                    count++;
                }
            }
            if(count <= leastreachCount){
                leastreachCount = count;
                resultcity = i;
            }
        }

        return resultcity;
    }
};