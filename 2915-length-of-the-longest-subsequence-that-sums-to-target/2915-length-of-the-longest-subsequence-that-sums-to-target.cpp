class Solution {
public:
    int dp[1001][1001];
    int solve(int i , int sum , vector<int>& nums , int target){

        int n = nums.size();

        if(i == n){
            if(sum == target){
                return 0;
            }else{
                return INT_MIN;
            }
        }

        if(dp[i][sum] != -1){
            return dp[i][sum];
        }

        int nottake = solve(i+1 , sum , nums , target);

        int take = INT_MIN;

        if(nums[i] <= target-sum){
            take = 1 +  solve(i+1 , sum+nums[i] , nums , target);
        }
    
        return dp[i][sum] = max(nottake , take);

    }
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();

        memset(dp , -1 , sizeof(dp));
        int ans = solve(0 , 0 , nums , target);

        if(ans < 0)return -1;
        return ans;
    }
};