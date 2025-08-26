class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i , int totalSum , vector<int>& nums){
        int n = nums.size();
        if(i >= n)return totalSum;

        if(dp[i][totalSum] != -1)return dp[i][totalSum];
        int res = 0;
        int nottake = solve(i+1 , totalSum , nums);

        int take = 0;
        if(nums[i] > totalSum){
            take = solve(i+1 , totalSum+nums[i] , nums);
        }
        res = max(nottake , take);

        return dp[i][totalSum] = res;
    }
    int maxTotalReward(vector<int>& rewardValues) {
        sort(rewardValues.begin() , rewardValues.end());
        int n = rewardValues.size();
        dp.resize(n+1 , vector<int>(rewardValues.back()*2 , -1));
        return solve(0 , 0 , rewardValues);
    

    }
};