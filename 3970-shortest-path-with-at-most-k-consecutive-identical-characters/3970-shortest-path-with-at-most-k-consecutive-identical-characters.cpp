class Solution {
public:
    const long long INF = 1e18; 
    long long id(int node , int cnt , int k){
        return ((long long)node * (k+1) + cnt);
    }
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {

        vector<vector<pair<int , int>>> adj(n);

        for(auto it : edges){
            adj[it[0]].push_back({it[1] , it[2]});
        }


        vector<long long> dis((long long)n*(k+1) , INF);


        priority_queue< tuple<long long , int , int> , vector<tuple<long long , int , int>> , greater<tuple<long long , int , int>>>pq;

        dis[id(0 , 1 ,k)] = 0;
        pq.push({0 , 0 , 1}); // dis , node , cnt


        while(!pq.empty()){
            auto [d , u , cnt] = pq.top();
            pq.pop();

            if(d != dis[id(u , cnt , k)])continue;


            for(auto it : adj[u]){
                int v = it.first;
                int w = it.second;

                int newcnt = cnt;

                if(labels[u] == labels[v]){
                    newcnt++;
                    if(newcnt > k ){
                        continue;
                    }
                }else{
                    newcnt = 1;
                }

                long long newd = d + w;
                long long idx = id(v , newcnt , k);

                if(newd < dis[idx]){
                    dis[idx] = newd;
                    pq.push({newd , v , newcnt});
                }
            }
        }
        long long ans = INF;

        for(int i=1 ; i<= k ; i++){
            ans = min(ans , dis[id(n-1 , i , k)]);
        }

        if(ans == INF)return -1;
        return (int)ans;
    }
};