class Solution {
public:
    vector<long long> dp;
    long long solve(int i , vector<vector<int>>& questions){
        int n = questions.size();

        if(i >= n)return 0;

        if(dp[i] != -1)return dp[i];

        long long res = 0;

        res = max(res , solve(i+1 , questions));
        res = max(res , questions[i][0] + solve(i+questions[i][1]+1 , questions));

        return dp[i] = res;
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        dp.assign(n+1 , -1);
        return solve(0 , questions);
    }
};