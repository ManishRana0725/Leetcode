class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> adj[n];
        for(auto it: prerequisites){
            adj[it[1]].push_back(it[0]);
        }

        vector<int> Indegre(n , 0);
        for(int i=0;i<n;i++){
            for(auto it: adj[i]){
                Indegre[it]++;
            }
        }

        queue<int> q;
        for(int i=0;i<n;i++){
            if(Indegre[i] == 0){
                q.push(i);
            }
        }

        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(auto it : adj[node]){
                Indegre[it]--;
                if(Indegre[it] == 0){
                    q.push(it);
                }
            }
        }

        if(topo.size() == n)return true;
        return false;

        
    }
};