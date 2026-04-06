// class Solution {
// public:
//     int dp[5005][5005];
//     int solve(int i , int peak , int  k , vector<int>& nums){

//         int n = nums.size();
//         if(i >= n-1){
//             if(peak == k) return 0;
//             return INT_MAX;
//         }
//         if(peak == k){
//             return 0;
//         }

//         if(dp[i][peak] != -1)return dp[i][peak];
//         // nottake 
//         int nottake = solve(i+1 , peak , k , nums);

//         // take 
//         int maxi = max(nums[i-1] , nums[i+1]);
//         int cost = 0;
//         if(nums[i] <= maxi){
//             cost = (maxi + 1 ) - nums[i];
//         }
        
//         int take = INT_MAX;
//         int s1 =  solve(i+2 , peak+1 , k , nums);
//         if(s1 != INT_MAX){
//             take = cost + s1;
//         }
        
//         return dp[i][peak] = min(take , nottake);
//     }
//     int minOperations(vector<int>& nums, int k) {
//         int n = nums.size();

//         if(k == 0)return 0;
//         vector<int> v;
        
//         v.push_back(nums[n-1]);
//         for(int i = 0; i < n; i++){
//             v.push_back(nums[i]);
//         }
//         v.push_back(nums[0]);

//         memset(dp , -1 , sizeof(dp));

//         int ans = solve(1 , 0 , k , v);

//         if(ans == INT_MAX) return -1;
//         return ans;
//     }
// };
class Solution {
public:
    long long eval(vector<int> &nums, int start, int end, int k, vector<int> &cost) {
        int n = nums.size();

        vector<vector<long long>> dp(n + 2, vector<long long>(k + 1, INT_MAX));
        dp[start][0] = 0;

        for (int i = start; i <= end; i++) {
            for (int j = 0; j <= k; j++) {
                if (dp[i][j] == INT_MAX) continue;

                // Skip current
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);

                // Take current
                if (j + 1 <= k) {
                    dp[i + 2][j + 1] = min(dp[i + 2][j + 1], dp[i][j] + cost[i]);
                }
            }
        }

        return min(dp[end + 1][k], dp[end + 2][k]);
    }
    
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        if (k > n / 2) return -1;
        if (k == 0) return 0;
        if (n == 2) return nums[0] == nums[1] ? 1 : 0;

        vector<int> cost(n);
        for (int i = 0; i < n; i++) {
            int left = nums[(i - 1 + n) % n];
            int right = nums[(i + 1) % n];
            cost[i] = max(0, max(left, right) + 1 - nums[i]);
        }

        long long ans = INT_MAX;

        // Case 1: skip index 0
        ans = min(ans, eval(nums, 1, n - 1, k, cost));

        // Case 2: take index 0
        if (k >= 1) {
            long long val = cost[0] + eval(nums, 2, n - 2, k - 1, cost);
            ans = min(ans, val);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};