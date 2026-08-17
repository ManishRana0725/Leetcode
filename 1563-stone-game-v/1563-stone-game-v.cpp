class Solution {
public:
    
    int solve(int l , int r , vector<int>& prefix , vector<vector<int>>& dp){

        if(l >= r )return 0;
        
        int ans = 0;
        if(dp[l][r] != -1)return dp[l][r];

        for(int i = l ; i <= r-1 ; i++){

            int leftsum = prefix[i] - ((l-1 >= 0) ? prefix[l-1] : 0);
            int rightsum = prefix[r] - prefix[i];

            if(leftsum < rightsum){
                ans = max(ans , leftsum + solve(l , i , prefix , dp));
            }else if(rightsum < leftsum){
                ans = max(ans , rightsum + solve(i+1 , r , prefix , dp));
            }else{
                ans = max(ans , leftsum + max(solve(l , i , prefix , dp) , solve(i+1 , r , prefix , dp)));
            } 
        }

        return dp[l][r] = ans;

    }
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<int> prefix(n , 0);
        prefix[0] = stoneValue[0];
        for(int i=1; i<n ; i++){
            prefix[i] = stoneValue[i] + prefix[i-1] ;
        }

        vector<vector<int>> dp(n+1 , vector<int>(n+1 , 0));

        //return solve(0 , n-1 , prefix , dp);


        for(int l = n-1 ; l >= 0 ; l--){

            for(int r = 0 ; r < n ; r++){

                int ans = 0;
                for(int i = l ; i <= r-1 ; i++){

                    int leftsum = prefix[i] - ((l-1 >= 0) ? prefix[l-1] : 0);
                    int rightsum = prefix[r] - prefix[i];

                    if(leftsum < rightsum){
                        ans = max(ans , leftsum + dp[l][i]);
                    }else if(rightsum < leftsum){
                        ans = max(ans , rightsum + dp[i+1][r]);
                    }else{
                        ans = max(ans , leftsum + max(dp[l][i] , dp[i+1][r] )  );
                    } 
                }

                dp[l][r] = ans;
            }
        }
        return dp[0][n-1];
    }
};