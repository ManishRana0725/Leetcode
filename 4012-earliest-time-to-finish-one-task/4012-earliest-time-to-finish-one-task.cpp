class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int n = tasks.size();
        int ans = INT_MAX;

        for(int i=0 ; i<n ;i++){
            int s = tasks[i][0];
            int  d = tasks[i][1];

            ans = min(ans , s+d);
        }
        return ans;
    }
};