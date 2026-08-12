class Solution {
public:
    

    int solve(int i , int j , vector<vector<int>>& mat , vector<vector<int>>& dp){
        int n = mat.size();
        int m = mat[0].size();

        if(i >= n || j >= m)return 0;

        if(dp[i][j] != -1)return dp[i][j];
        
        int right = 0 , diag = 0 , down = 0;
        int len = 0;

        right = solve(i , j+1 , mat , dp );
        diag = solve(i+1 , j+1 , mat , dp );
        down = solve(i+1 , j , mat , dp );


        if(mat[i][j] == 1){
            len = min({right , diag , down});
            len++;
            dp[i][j] = len;
        }else{
            dp[i][j] = 0;
        }

       
        return dp[i][j];
    }


    int maxArea(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> dp(n , vector<int>(m , -1));
        
        int ans =  solve(0 , 0 , mat , dp);

        
        int s = 1 ; 
        int e = min(n , m);
        ans = 0;
        while(s <= e){
            int mid = s + (e - s)/2;

            int r1 = 500 , r2 = 0;
            int c1 = 500 , c2 = 0;

            for(int i=0 ; i<n ; i++){
                for(int j=0 ; j<m ; j++){

                    if(dp[i][j] >= mid){
                        r1 = min(r1 , i);
                        c1 = min(c1 , j);

                        r2 = max(r2 , i);
                        c2 = max(c2 , j);
                    }
                }
            }

            if( r2 - r1 >= mid  || c2 - c1 >= mid){
                ans = mid;
                s = mid+1;
            }else{
                e = mid - 1;
            }

        }

        return ans*ans;
    }
};