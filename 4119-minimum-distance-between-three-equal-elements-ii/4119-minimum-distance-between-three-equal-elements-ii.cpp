class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;

       
        for (int i = 0; i < n; i++)
            mp[nums[i]].push_back(i);

        int ans = INT_MAX;
        bool found = false;

        
        for (auto& p : mp) {
            auto& v = p.second;
            if (v.size() < 3) continue;  

            for (int i = 0; i + 2 < v.size(); i++) {
                int dist = 2 * (v[i+2] - v[i]);
                ans = min(ans, dist);
                found = true;
            }
        }

        return found ? ans : -1;
    }
};