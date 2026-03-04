class DSU{
    public:
    vector<int> parent , rank;
    
    DSU(int n){
        parent.resize(n);
        rank.resize(n);

        for(int i=0 ; i<n ; i++){
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int findpar(int u){
        
        if(parent[u] == u){
            return u;
        }

        return parent[u] = findpar(parent[u]);

    }

    void merge(int u , int v){
        int upar = findpar(u);
        int vpar = findpar(v);

        if(upar == vpar) return;

        if(rank[upar] < rank[vpar] ){
            parent[upar] = vpar;
        }else if(rank[vpar] < rank[upar]){
            parent[vpar] = upar;
        }else{
            parent[vpar] = upar;
            rank[upar]++;
        }
    }
};
class Solution {
public:
    bool check(string & s1 , string & s2){
        int n = s1.size();

        int similar = 0;

        for(int i=0 ; i<n ; i++){
            if(s1[i] == s2[i])similar++;
        }

        if(similar >= n-2){
            return true;
        }else{
            return false;
        }
    }
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();

        DSU d(n);

        for(int i=0 ; i<n ; i++){
            for(int j=i+1 ; j<n ; j++){
                
                if(check(strs[i] , strs[j])){
                    d.merge(i , j);
                }
                
            }
        }

        unordered_set<int > st;

        for(int i=0 ; i<n ; i++){
            st.insert(d.findpar(i));
        }

        return st.size();
    }
};