class Solution {
public:

    int M = 1000000007;
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    int solve(int i , int one , int two , vector<int>& nums , vector<vector<vector<int>>>& dp){
        if( i < 0){
            return (one == two && one != 0);
        }

        if(dp[i][one][two] != -1)return dp[i][one][two];
        int result = 0;

        result = (result + solve(i-1 , gcd(one , nums[i]) , two , nums , dp)%M)%M;
        result = (result + solve(i-1 , one , gcd(two , nums[i]) , nums , dp)%M)%M;
        result = (result + solve(i-1 , one , two , nums , dp)%M)%M;

        return dp[i][one][two] = result;
    }
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        vector<vector<vector<int>>> dp(n+1 , 
                vector<vector<int>> (maxi+1 , vector<int>(maxi +1 , -1)));
        return solve(n-1 , 0 , 0 , nums , dp);
    }
};