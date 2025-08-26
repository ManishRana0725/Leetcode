class Solution {
public:
    vector<int> dp;
    int solve(int i , int k  , vector<int>& arr){
        int n = arr.size();

        if(i >= n)return 0;

        if(dp[i] != -1)return dp[i];
        int len = 0;
        int maxi = INT_MIN;
        int ans = INT_MIN;
        for(int j = i ; j < min(n , i+k ) ; j++){
            len++;
            maxi = max(maxi , arr[j]);
            ans = max(ans , len*maxi + solve(j+1 , k , arr));

        }

        return dp[i] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        dp.resize(n+1 , -1);
        return solve(0 , k , arr);
    }
};