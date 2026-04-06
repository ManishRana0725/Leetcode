class Solution {
public:
    bool dfscheck(int node , vector<vector<int>>& graph , vector<int>& vis , 
                    vector<int>& pathvisited , vector<int>& check)
    {
        vis[node] = 1;
        pathvisited[node] = 1;
        check[node] =0;
        for(auto it : graph[node]){
            if(!vis[it]){
                if(dfscheck(it , graph , vis , pathvisited , check) == true){
                    check[node] = 0;
                    return true;
                }
            }
            else if(pathvisited[it]){
                check[node] = 0;
                return true;
            }
        }
        check[node] = 1;
        pathvisited[node] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int q = graph.size();
        vector<int> vis(q,0);
        vector<int> pathvisited(q,0);
        vector<int> safeNode;
        vector<int> check(q , 0);
        for(int i=0;i<q;i++){
            if(!vis[i]){
                dfscheck(i , graph , vis , pathvisited , check);

            }
         
        }

        for(int i=0;i<q;i++){
            if(check[i]){
                safeNode.push_back(i);
            }
        }

        return safeNode;
    }
};