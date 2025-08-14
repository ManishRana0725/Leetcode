class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i ,int k , vector<vector<int>>& piles){
        int n = piles.size();
        if(k == 0)return 0;
        if(i >= n)return 0;

        if(dp[i][k] != -1)return dp[i][k];
        int res = 0;
        res = solve(i+1 , k , piles);
        int sum = 0;
        for(int ind = 0 ; ind < piles[i].size() ; ind++){
            sum += piles[i][ind];
            if( k >= ind+1){
                res = max(res , sum + solve(i+1 , k - (ind+1) , piles));
            }else{
                break;
            }
        }

        return dp[i][k] = res;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        dp.resize(n+1  , vector<int> (k+1 ,-1));

        return solve(0 , k , piles);
    }
};