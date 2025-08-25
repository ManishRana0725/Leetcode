class Solution {
public:

    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref_max(n);
        vector<int> suff_min(n);
       
        pref_max[0] = nums[0];
        for(int i=1 ;i<n ; i++){
            pref_max[i] = max(nums[i] , pref_max[i-1]);
        }

        suff_min[n-1] = nums[n-1];
        for(int i=n-2 ; i>=0 ; i--){
            
            suff_min[i] = min(suff_min[i+1] , nums[i]);
        }


       vector<int> ans(n);
        ans[n-1] = pref_max[n-1];
       for(int i=n-2; i>= 0 ; i--){
            
            ans[i] = pref_max[i];

            if(pref_max[i] > suff_min[i+1]){
                ans[i] = max(ans[i] , ans[i+1]);
            }
       }

       return ans;

    }
};

