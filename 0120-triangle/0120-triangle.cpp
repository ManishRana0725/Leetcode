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
        dp.assign(n+1 , vector<int>(n+1 , 0));
        //return solve(0 , 0 , triangle);


        


        for(int i=n-1 ; i>= 0 ; i--){
            for(int j = i; j>= 0 ; j-- ){
                

                int down =  triangle[i][j] + dp[i+1][j];
                int dia = triangle[i][j] + dp[i+1][j+1];


                dp[i][j] = min(down , dia);
            }
        }
        
        return dp[0][0];
        
        
    }
};