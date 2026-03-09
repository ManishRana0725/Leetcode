class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        
        int n = plantTime.size();
        vector<pair<int , int>> growfirst;
        int sum = 0;
        for(int i=0 ; i<n ;i++){
            int u = plantTime[i];
            int v = growTime[i];
            sum += u;
            growfirst.push_back({v , u});
        }

        sort(growfirst.begin() , growfirst.end());

        reverse(growfirst.begin() , growfirst.end());
        int ans = 0;    
        int plantime = 0;

        for(auto it : growfirst){

            plantime += it.second;

            ans = max(ans , plantime + it.first);
        }
        return ans;
    }
};