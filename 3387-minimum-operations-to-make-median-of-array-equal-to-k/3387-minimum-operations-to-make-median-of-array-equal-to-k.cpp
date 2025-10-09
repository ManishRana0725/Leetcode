class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        long long ans = 0;
        int mid = (n%2 != 0) ? n/2 : n/2;
        if(nums[mid] > k){
           // change all larger value to the left to k 
           for(int i=0 ; i<= mid ; i++){
                if(nums[i] > k){
                    ans += abs(k - nums[i]);
                }
                
           }
        }
        else if(nums[mid] < k){
            // chabfe all smaller vlaue to the right to k
            for(int i=mid ; i<n ;i++){
                if(nums[i] < k){
                    ans += abs(k - nums[i]);
                }
            }

        }else{
            return 0;
        }  

        return ans;

    }
};