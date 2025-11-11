class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> vis(n, 0);
        long long total = accumulate(nums.begin(), nums.end(), 0LL);
        vector<long long> ans;
        
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for (int i = 0; i < n; i++) pq.push({nums[i], i});
        
        for (auto &q : queries) {
            int ind = q[0], k = q[1];
            
         
            if (!vis[ind]) {
                vis[ind] = 1;
                total -= nums[ind];
            }

            
            while (k > 0 && !pq.empty()) {
                auto [val, idx] = pq.top();
                pq.pop();
                if (vis[idx]) continue; 
                vis[idx] = 1;
                total -= val;
                k--;
            }

            ans.push_back(total);
        }
        
        return ans;
    }
};