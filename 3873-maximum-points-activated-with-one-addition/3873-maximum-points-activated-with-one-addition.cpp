class DSU{
    public:
    vector<int> parent , size;

    DSU(int n){
        parent.resize(n);
        size.resize(n);

        for(int i = 0 ; i<n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findpar(int u){
        if(parent[u] == u)return u;

        return parent[u] = findpar(parent[u]);
    }

    void merge(int u , int v){
        int ul_pu = findpar(u);
        int ul_pv = findpar(v);

        if(ul_pu == ul_pv)return;

        if(size[ul_pu] < size[ul_pv]){
            size[ul_pv] += size[ul_pu];
            parent[ul_pu] = ul_pv;
        }else{
            size[ul_pu]+= size[ul_pv];
            parent[ul_pv] = ul_pu;
        }
    }

};
class Solution {
public:
    int maxActivated(vector<vector<int>>& points) {
        int n = points.size();

        unordered_map<int , vector<int>> x , y ;

        for(int i=0 ; i<n ; i++){
            x[points[i][0]].push_back(i);
            y[points[i][1]].push_back(i);
        }
        DSU dsu(n);
        for(auto it : x){
            vector<int> v = it.second;

            for(int i=0 ; i<v.size()-1 ; i++){
                dsu.merge(v[i] , v[i+1]);
            }
        }
        for(auto it : y){
            vector<int> v = it.second;

            for(int i=0 ; i<v.size()-1 ; i++){
                dsu.merge(v[i] , v[i+1]);
            }
        }
        

        int m1 = 0 , m2 = 0;

        for(int i=0 ; i<n ; i++){
            if(dsu.parent[i] == i){
                int sz = dsu.size[i];

                if(sz > m1){
                    m2 = m1;
                    m1 = sz;
                }else if(sz > m2){
                    m2 = sz;
                }
            }
        }

        if(m2 == 0)return m1+1;
        return m2+m1+1;
    }
};