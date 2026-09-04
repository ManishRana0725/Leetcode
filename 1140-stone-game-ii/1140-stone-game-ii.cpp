class Solution {
public:

    int solve(int i , vector<int>& piles , int m , int flag , vector<vector<vector<int>>>& dp) {

        int n = piles.size();

        if(i >= n)
            return 0;

        if(dp[flag][i][m] != -1)
            return dp[flag][i][m];

        int ans = (flag == true) ? -1 : INT_MAX;
        int sum = 0;

        for(int k = i; k <= min(n - 1, i + 2*m - 1); k++) {

            sum += piles[k];

            int newm = max(m, k - i + 1);

            if(flag) {
              
                ans = max(ans , sum + solve(k + 1, piles, newm, false, dp));
            }
            else {
                ans = min( ans , solve(k + 1, piles, newm, true, dp));
            }
        }

        return dp[flag][i][m] = ans;
    }

    int stoneGameII(vector<int>& piles) {

        int n = piles.size();

        vector<vector<vector<int>>> dp( 2 , vector<vector<int>>(n+1 ,  vector<int>(n+1, -1)));

        return solve(0, piles, 1, true, dp);
    }
};