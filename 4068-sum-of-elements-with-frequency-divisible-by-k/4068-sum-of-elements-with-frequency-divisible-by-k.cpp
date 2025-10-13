class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> mpp(101 , 0);
        for(int i=0 ; i<n ;i++){
            mpp[nums[i]]++;
        }
        int ans = 0;
        for(int i=1 ; i< 101 ; i++){

            if(mpp[i] % k == 0){
                ans += mpp[i] * i;
            }
        }
        return ans;


    }
};