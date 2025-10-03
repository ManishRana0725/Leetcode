class Solution {
public:
    const int M = 1e9+7;
    vector<int> dp;
    int solve(int x , int delay , int forget){

        if(x == 1)return 1;
        int result = 0;

        if(dp[x] != -1){
            return dp[x];
        }

        for(int day = x - forget+1 ; day <= x - delay ; day++){
            if(day >= 1){
                result = (result + solve(day , delay , forget))%M;
            }
            
        }

        return dp[x] = result ;
    }
    int peopleAwareOfSecret(int n, int delay, int forget) {
        dp.assign(n+1 , -1);

        int total = 0;

        for(int day = n-forget+1 ; day <= n ; day++){
            if(day>=1){
                total = (total + solve(day , delay , forget))%M;
            }
        }
        return total;
    }
};