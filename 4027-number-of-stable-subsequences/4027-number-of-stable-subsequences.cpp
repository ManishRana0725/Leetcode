class Solution {
public:
    const int M = 1000000000+7;
    vector<vector<vector<int>>> dp;
    int solve(int i , int prev_parity , int count , vector<int>& nums){
        int n = nums.size();
        if(i == n)return 1;

        if(dp[i][prev_parity][count] != -1)return dp[i][prev_parity][count];
        int parity = 0;
        if(nums[i] %2 != 0)parity = 1;
        int res = 0;
        if(parity == prev_parity && count < 2){
            res = (res + solve(i+1 , prev_parity , count+1 , nums ))%M;
        }else if(parity != prev_parity){
            res = (res + solve(i+1 , parity , 1 , nums ))%M;
        }


        // sktp
        res = (res + solve(i+1 , prev_parity , count , nums))%M;
        return dp[i][prev_parity][count] = res;
    }
    int countStableSubsequences(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n+1 , vector<vector<int>> (3 , vector<int>(3 , -1)));
        return solve(0 , 2 , 0 , nums)-1;
    }
};