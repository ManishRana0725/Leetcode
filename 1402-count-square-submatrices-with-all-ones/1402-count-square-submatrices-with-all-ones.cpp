class Solution {
public:
    vector<vector<int>> dp;
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        dp.resize(n , vector<int>(m , 0));

        for(int i=n-1 ; i>=0 ; i--){
            for(int j = m-1 ; j>= 0 ; j--){
                int ans = 0;
                if(matrix[i][j] == 1){
                    ans = 1;
                    int right = 0;
                    int down = 0;
                    int dis = 0;

                    if(j+1 < m) right = dp[i][j+1] ;
                    if(i+1 < n) down = dp[i+1][j];
                    if(i+1 <n && j+1 < m) dis =  dp[i+1][j+1];
                    ans += min(right , min(down , dis));
                }
                
                dp[i][j] = ans;
            }
        }
        
        int sum = 0;
        for(int i=0 ; i<n ;i++){
            for(int j=0 ; j<m ;j++){  
                sum += dp[i][j];
            }
        }
        return sum;
    }
};