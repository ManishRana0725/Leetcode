class Solution {
public:
    int solve(int i , int prev , vector<int>& arr1, vector<int>& arr2 , map<pair<int , int> , int>& dp){
        int n = arr1.size();

        if(i >= n)return 0;

        if(dp.count({i , prev})){
            return dp[{i , prev}];
        }
        int result1 = 1e9+1;
        if(arr1[i] > prev){
            result1 = solve(i+1 , arr1[i] , arr1 , arr2 , dp);
        }

        auto it = upper_bound(arr2.begin() , arr2.end() , prev);
        int result2 = 1e9+1;
        if(it != arr2.end()){
            result2 = 0;
            int j = it - arr2.begin();
            result2 = 1+solve(i+1 , arr2[j]  , arr1 , arr2 , dp);
            
        }
        
        return dp[{i , prev}] = min(result1 , result2);

    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int m = arr2.size();

        sort(arr2.begin() , arr2.end());

        map<pair<int , int> , int> dp;

        int ans = solve(0 , INT_MIN , arr1 , arr2 , dp);

        if(ans == 1e9+1){
            return -1;
        }
        return ans;

    }
};