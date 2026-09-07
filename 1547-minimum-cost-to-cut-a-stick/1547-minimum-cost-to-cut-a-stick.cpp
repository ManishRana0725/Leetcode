class Solution {
public:
    int solve(int i , int j , vector<int>& cuts , vector<vector<int>>& dp){
        if(i > j)return 0;


        if(dp[i][j] != -1)return dp[i][j];

        int mini = INT_MAX;         
        for(int k=i;k<=j;k++){

            int cost = solve(i , k-1, cuts , dp) + solve(k+1 , j , cuts , dp) + cuts[j+1] - cuts[i-1];
            mini = min(cost , mini);

        }
        return dp[i][j] = mini;
    }
    int minCost(int n, vector<int>& cuts) {
        int m = cuts.size();
        cuts.insert(cuts.begin() , 0);
        cuts.insert(cuts.end() , n);
        sort(cuts.begin() , cuts.end());
        vector<vector<int>> dp(m+2 , vector<int>(m+2  , 0));
        //return solve(1 , m , cuts , dp);

        for(int i=m;i>=1; i--){
            for(int j = 1 ; j<=m ;j++){
                if(i > j )continue;

                int mini = INT_MAX;         
                for(int k=i;k<=j;k++){

                    int cost = dp[i][k-1] + dp[k+1][j] + cuts[j+1] - cuts[i-1];
                    mini = min(cost , mini);

                }

                dp[i][j] = mini;
            }
        }

        return dp[1][m];
    }
};