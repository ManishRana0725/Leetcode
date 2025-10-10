class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        int l = 0; 
        int r = 1;

        while(r < n ){

            if(nums[r] != nums[r-1]){
                ans += r - l ;
                r++;
            }else{
                if(r != n-1){
                    l = r;
                    r = l+1;
                    
                }else{
                    r++;
                }
            }
        }

        ans += n;
        return ans;
    }
};