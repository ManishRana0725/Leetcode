class DSU{
    public:
    vector<int>parent , rank;
    DSU(int n){
        parent.resize(n);
        rank.resize(n , 0);

        for(int i=0 ; i<n ;i++){
            parent[i] = i;
            
        }
    }

    int findpar(int u){

        if(parent[u] == u){
            return u;
        }

        return parent[u] = findpar(parent[u]);
    }

    void merge(int u , int v){
        int parv = findpar(v);
        int paru = findpar(u);

        if(paru == parv)return;
        
        if(rank[paru] < rank[parv]){
            parent[paru] = parv;
        }else if(rank[parv] < rank[paru]){
            parent[parv] = paru;
        }else{
            parent[paru] = parv;
            rank[parv]++;
        }
    }
};
class Solution {
public:
    bool solve(int mid , int k , int n , vector<vector<int>>& mustEdge , vector<vector<int>>& optEdge){

        vector<vector<int>> store;
        DSU dsu(n);
        for(auto it : mustEdge){   
            int u = it[0];
            int v = it[1];
            int s = it[2];
            int m = it[3];

            if(s < mid)return false;

            if(dsu.findpar(u)==dsu.findpar(v))
                return false;

            dsu.merge(u , v);

        }

       

        for(int i = 0 ; i<optEdge.size() ; i++){

            int u = optEdge[i][1];
            int v = optEdge[i][2];
            int s = optEdge[i][0];

            if(dsu.findpar(u)==dsu.findpar(v))continue;

            if(s >=  mid){
                dsu.merge(u , v);
            }
            else if(k > 0 && s*2 >= mid){
                dsu.merge(u , v);
                k--;
            }
        }

        int comp=0;
        for(int i=0;i<n;i++)
            if(dsu.findpar(i)==i)
                comp++;

        return comp==1;

    }
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        
        vector<vector<int>> mustEdge;
        vector<vector<int>> optEdge;

        for(auto &e:edges){

            if(e[3]==1)
                mustEdge.push_back(e);
            else
                optEdge.push_back({e[2],e[0],e[1]});
        }

        sort(optEdge.rbegin(),optEdge.rend()); 


        int s = 1; 
        int e = 2*1e5;
        int ans = -1;
        while(s <= e){
            int mid = s + (e-s)/2;

            if(solve(mid  , k , n , mustEdge , optEdge)){
                ans = mid;
                s = mid+1;
            }else{
                e = mid-1;
            }
        }
        return ans;
    }
};