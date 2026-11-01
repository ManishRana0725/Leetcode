class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& locked, int k) {
        int n = nums.size();
        int maxi = -1;
        int ans = 0;
        for(int i = 0; i < n ;i++){
            maxi = max(nums[i], maxi);
            if(locked[i] == 1){
                if(!(nums[i] == i+1 && maxi == i + 1)){
                    ans++;
                }
            }
        }
        if(ans > k){
            return -1;
        }
        for(int i = 0;i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(nums[i] > nums[j]){
                    ans++;
                }
            }
        }
        return ans;
    }
};