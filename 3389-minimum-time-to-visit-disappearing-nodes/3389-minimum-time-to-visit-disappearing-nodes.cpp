class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<vector<pair<int , int>>> adj(n);
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int len = it[2];
            adj[u].push_back({ v , len});
            adj[v].push_back({ u , len});
        }

        priority_queue<tuple<int , int , int> , vector<tuple<int , int , int>> , greater<tuple<int , int , int>> > pq;

        vector<int> ans(n , INT_MAX);
        ans[0] = 0;

        pq.push({ 0 , 0 , -1}); // time , node , parent ;
        while(!pq.empty()){
            auto [time , node , parent] = pq.top();
            pq.pop();
            
            if (time != ans[node]) continue;          
            //if (time >= disappear[node]) continue;

            for(auto it : adj[node]){
                int vertice = it.first;
                int len = it.second;
            
                if(disappear[vertice] > time + len && ans[vertice] > time + len ){
                    
                    pq.push({time+len , vertice , node});
                    ans[vertice] = time+len;
                }
            }
        }

        for(auto & it : ans){
            if(it == INT_MAX){
                it = -1;
            }
        }

        return ans;
    }
};