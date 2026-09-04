class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {

        int n = nums.size();

        vector<int> maxi(n);
        int maxiele = -1;
        for(int i=0; i<n; i++){
            maxiele = max(maxiele , nums[i]);
            maxi[i] = maxiele;
        }
        int mini = nums[n-1];
        int ans = INT_MAX;
        for(int i= n-1 ; i>= 0 ; i--){
            mini = min(mini , nums[i]);

            int score = maxi[i] - mini;

            if(score <= k){
                ans = min(ans , i);
            }
        }
        if(ans == INT_MAX)return -1;
        else{
            return ans;
        }
    }
};