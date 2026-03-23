class Solution {
public:
    void dfs(int src, vector<vector<int>>& isConnected, vector<bool>& visited) {
        visited[src] = true;
        
        for(int i=0; i<isConnected[src].size(); i+=1) {
            if(isConnected[src][i] == 1 && visited[i] == false) {
                dfs(i, isConnected, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<bool>vis(V,false);
        
        int cnt = 0; 
        for(int i = 0;i<V;i++) {
            
            if(!vis[i]) {
                cnt++;
               dfs(i, isConnected , vis); 
            }
        }
        return cnt; 
    }
};