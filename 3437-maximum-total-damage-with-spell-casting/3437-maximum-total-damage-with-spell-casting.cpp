class Solution {
public:
    vector<long long> dp;
    long long solve(int i , vector<int>& nums ){
        int n = nums.size();
        if(i >= n)return 0;
        if(i == n-1)return nums[i];


        if(dp[i] != -1)return dp[i];

        int j = i;
        long long sum = 0;
        while (j < n && nums[j] == nums[i]) {
            sum += nums[j];
            j++;
        }
        //int same = upper_bound(nums.begin()+i+1 , nums.end() , nums[i])-nums.begin();
        int it = upper_bound(nums.begin()+i+1, nums.end(), nums[i]+2) - nums.begin();
        
        long long nottake = solve(j, nums);
        
        long long take = sum + solve(it , nums);
       
        return dp[i] = max(take , nottake) ;
    }
    long long maximumTotalDamage(vector<int>& power) {
        sort(power.begin() , power.end());
        int n = power.size();
        dp.resize(n+1 , -1);
        return solve(0 , power);

    }
};


