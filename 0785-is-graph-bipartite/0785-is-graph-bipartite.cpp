class Solution {
public:
    bool check(int start , vector<vector<int>>& graph , vector<int>& col ){
        queue<int> q ;
        int n = graph.size();
        q.push(start);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for( auto it : graph[node]){
                if(col[it] == -1){
                    col[it] = !col[node];
                    q.push(it);
                }
                else if(col[it] == col[node]){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> col( n , -1);
        for(int i=0;i<graph.size();i++){
            if(col[i] == -1){
                if(check(i , graph , col) == false){
                    return false;
                }
            }
        }
        return true;
       
    }
};