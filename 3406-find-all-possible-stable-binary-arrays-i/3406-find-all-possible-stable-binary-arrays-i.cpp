class Solution {
public:
    const int M = 1000000000+7;
    vector<vector<vector<vector<int>>>> dp;
    
    int solve(int zero , int one , int last , int count , int limit ){

        if(zero == 0 && one == 0){
            return 1;
        }
        int result = 0;
        if(dp[zero][one][last][count] != -1)return dp[zero][one][last][count];
        if(last == 0){
            
            if(one > 0  ){
                result = (result + solve(zero , one-1 , 1 , 1 , limit))%M;
            }
            if(zero > 0 && count < limit ){
                result = (result + solve(zero-1 , one , 0 , count+1 , limit))%M;
            }
        }

        if(last == 1){
            
            if(one > 0 && count < limit ){
                result = (result + solve(zero , one-1 , 1 , count+1 , limit))%M;
            }
            if(zero > 0 ){
                result = (result + solve(zero-1 , one , 0 , 1 , limit))%M;
            }
        }

        return dp[zero][one][last][count] = result;
        

        
        
    }
    int numberOfStableArrays(int zero, int one, int limit) {
        string s = "";
        int n = zero + one;

        dp.resize(zero+1 , vector<vector<vector<int>>>(one+1 , vector<vector<int>> (2 , vector<int>( limit+1 , -1))));
        return ((solve( zero-1 , one , 0 , 1 , limit ) + solve(zero , one-1 , 1 , 1 , limit)))%M;
    }
};