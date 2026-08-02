class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        
        int n = nums.size();    
        int count = 0;

        for(int i=0 ; i<n ; i++){
            int odd = 0 , even  = 0;
            for(int j = i ; j<n; j++){

                if(nums[j]%2 == 0){
                    even++;
                }else{
                    odd++;
                }

                if((odd > 0) && (even*b <= odd*a) ){
                    count++;
                }
            }
        }
        return count;
    }
};