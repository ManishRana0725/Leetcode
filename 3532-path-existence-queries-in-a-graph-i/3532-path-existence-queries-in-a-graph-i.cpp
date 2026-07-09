class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> comp(n );
        int component = 0;
        comp[0] = component;
        for(int i=1 ; i<n ; i++){

            if(nums[i] - nums[i-1] > maxDiff)component++;

            comp[i] = component;
        }

        vector<bool> ans(queries.size() , false);
        int i=0;
        for(auto it : queries){

            int u = it[0];
            int v = it[1];

            if(comp[u] == comp[v])ans[i] = true;

            i++;
        }
        return ans;
    }
};