class Solution {
public:
    int dp[250][250];
    int solve(int i , int j , int k , vector<int>& nums){
        int n = nums.size();
        int subxor = 0;

        if(k == 1){
            for(int ind = i ; ind <= j ; ind++){
                subxor ^= nums[ind];
            }
            return subxor;
        }

        if(dp[i][k] != -1)return dp[i][k];
        int ans = INT_MAX;
        for(int ind = i ; ind <= (j-k +1); ind++){
            subxor ^= nums[ind];

            ans = min(ans , max(subxor , solve(ind+1 , j , k-1 , nums)));
        }

        return dp[i][k] = ans;
    }
    int minXor(vector<int>& nums, int k) {
        int n = nums.size();
        memset(dp , -1 , sizeof(dp));
        return solve(0 , n-1 , k , nums);
    }
};