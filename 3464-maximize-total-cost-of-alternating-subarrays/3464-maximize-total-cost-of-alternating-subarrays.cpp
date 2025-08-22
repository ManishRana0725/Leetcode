class Solution {
public:
    vector<vector<long long>> dp;
    long long solve(int i , vector<int>& nums , int prev){

        int n = nums.size();
        if(i == n){
            return 0;
        }

        
        
        if(dp[i][prev] != -1)return dp[i][prev];
        // start new 
        long long res = nums[i] + solve(i+1 , nums , 1);
        
        if(prev){
            res = max(res , -nums[i] +solve(i+1 , nums , 0));
        }else{
            res = max(res , nums[i] + solve(i+1 , nums , 1));
        }

        return dp[i][prev] = res;

    }
    long long maximumTotalCost(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n+1 , vector<long long>(2 , -1));
        return solve(0 , nums , 0);
    }
};