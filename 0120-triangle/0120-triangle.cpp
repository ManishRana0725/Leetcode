class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i , int j ,vector<vector<int>>& triangle){
        int n = triangle.size();

        if(i == n-1){
            return triangle[i][j];
        }

        if(dp[i][j] != INT_MAX)return dp[i][j];
        int right =  triangle[i][j] + solve(i+1 , j , triangle);
        int right_dia = triangle[i][j] + solve(i+1 , j+1 , triangle);


        return dp[i][j] = min(right , right_dia);

    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        dp.assign(n+1 , vector<int>(n+1 , INT_MAX));
        return solve(0 , 0 , triangle);

        
    }
};