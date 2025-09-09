class Solution {
public:
    
    int maxScore(vector<vector<int>>& nums) {
        int n = nums.size();
        int m = nums[0].size();

        vector<vector<int>> prev_min(n+1, vector<int>(m+1));

        prev_min[0][0] = nums[0][0];

        for(int i= 1 ; i<n ; i++){
            prev_min[i][0] = min(nums[i][0] , prev_min[i-1][0]);
        }
        for(int i= 1 ; i<m ; i++){
            prev_min[0][i] = min(nums[0][i] , prev_min[0][i-1]);
        }
        for(int i = 1 ; i<n ;i++){
            for(int j= 1 ; j<m ;j++){
              
                prev_min[i][j] = min({prev_min[i-1][j] , prev_min[i][j-1] , nums[i][j] } );
            }
        }

        int ans = INT_MIN;

        for(int i = n-1; i>=0 ; i--){
            for(int j=m-1 ; j>= 0 ; j--){

                int b = INT_MAX;

                if(i-1 >= 0 )b = min(b , prev_min[i-1][j]);
                if(j-1 >= 0 )b = min(b , prev_min[i][j-1]);

                ans = max(ans , nums[i][j] - b);
            }
        }

        
        return ans;
    }
};