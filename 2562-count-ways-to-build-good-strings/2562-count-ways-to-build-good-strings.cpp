class Solution {
public:
    vector<int> dp;
    const int MOD = 1e9+7;
    int solve(int i , int low, int high, int zero, int one){
    
        int ans = 0;

        if(i == high ){
            ans++;
            return ans;
        }

        if(dp[i] != -1)return dp[i];
        if(low <= i ){
            ans++;
        }

        if(zero + i <= high ){
            ans +=  solve(i+zero , low , high , zero , one);
            ans %= MOD;
        }
        if(one + i <= high ){
            ans +=  solve(i+one , low , high , zero , one);
            ans %= MOD;
        }

        return dp[i] = ans;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        dp.assign(high +1 , -1);
        return solve(0 , low , high , zero , one);
        
    }
};