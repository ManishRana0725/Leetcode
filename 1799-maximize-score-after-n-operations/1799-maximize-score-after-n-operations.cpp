class Solution {
public:
    vector<vector<int>> dp;
    int solve(int times , vector<int>& nums , int mask , vector<vector<int>>& dp){
        int n = nums.size();

        if( times > n/2){
            return 0;
        }   

        if(dp[times][mask] != -1)return dp[times][mask];

        int ans = 0;

        for(int i = 0 ; i<n ; i++){

            if(mask & 1 << i ){
                continue;
            }            

            for(int j = i+1; j < n ; j++){

                if(mask & (1 << j))continue;
                int newmask = mask;
                newmask = mask | (1 << i);
                newmask = newmask | (1 << j);

                ans = max(ans , times*gcd(nums[i] , nums[j]) + solve(times+1 , nums , newmask , dp));

            }
        }

        return dp[times][mask] = ans ;
    }
    int maxScore(vector<int>& nums) {
        int mask = 0;
        int n = nums.size();
        vector<vector<int>> dp(n/1 , vector<int>(1 << n , -1));
        return solve(1 , nums , mask , dp);
    }
};