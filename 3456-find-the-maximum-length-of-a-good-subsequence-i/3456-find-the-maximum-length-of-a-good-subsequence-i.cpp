class Solution {
public:
    int dp[505][505][27];
    int solve(int i , int prev , vector<int>& nums , int k){
        int n = nums.size();

        if(k < 0)return INT_MIN;
        if(i == n)return 0;

        if(dp[i][prev+1][k] != -1){
            return dp[i][prev+1][k];
        }
        int nottake = solve(i+1 , prev  , nums , k);

        int take = 0;
        int newk = k;
        if(prev != -1 && nums[i] != nums[prev]){
            newk--;
        }

        take = 1 + solve(i+1 , i , nums , newk);
    
        return dp[i][prev+1][k] = max(take , nottake);
        
    }
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        memset(dp , -1 , sizeof(dp));
        return solve(0 , -1 , nums , k);
    }
};