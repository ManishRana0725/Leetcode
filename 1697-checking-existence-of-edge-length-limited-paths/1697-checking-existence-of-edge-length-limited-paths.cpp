class DisjointSet {
    vector<int> rank, parent, size;
    public:
        DisjointSet(int n) {
            rank.resize(n + 1, 0);
            parent.resize(n + 1);
            for (int i = 0; i <= n; i++) {
                parent[i] = i;
            }
        }

        int findUPar(int node) {
            if (node == parent[node])
                return node;
            return parent[node] = findUPar(parent[node]);
        }

        void unionByRank(int u, int v) {
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);
            if (ulp_u == ulp_v) return;
            if (rank[ulp_u] < rank[ulp_v]) {
                parent[ulp_u] = ulp_v;
            }
            else if (rank[ulp_v] < rank[ulp_u]) {
                parent[ulp_v] = ulp_u;
            }
            else {
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }

        
};
class Solution {
public:
    static bool cmp(vector<int>a , vector<int>b){
        return a[2] < b[2];
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        
        DisjointSet d(n);
        unordered_map<string , vector<int>> mpp; // to store original queries ind
        int m = queries.size();
        vector<bool> ans(m , false);
        for(int i=0 ; i<m ; i++){
            int p = queries[i][0];
            int q = queries[i][1];
            int limit = queries[i][2];

            string s = to_string(p) + "#" +
           to_string(q) + "#" +
           to_string(limit);

            mpp[s].push_back(i);
        }
        sort(queries.begin() , queries.end() , cmp);
        sort(edgeList.begin() , edgeList.end() , cmp);
        
        int i = 0;
        for(auto it : queries){
            int p = it[0];
            int q = it[1];
            int limit = it[2];

            while(i < edgeList.size()){
                if(edgeList[i][2] >= limit){
                    break;
                }

                int u = edgeList[i][0];
                int v = edgeList[i][1];
                int dis = edgeList[i][2];

                
                d.unionByRank(u , v);
                i++;
            }

            if(d.findUPar(p) == d.findUPar(q)){
                string s = to_string(p) + "#" +
                to_string(q) + "#" +
                to_string(limit);
                int ind = mpp[s].back();
                mpp[s].pop_back();
                ans[ind] = true;
            }
        }
        return ans;
    }
};