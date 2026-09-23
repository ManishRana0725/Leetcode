class Solution {
public:
    
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int totalsum = 0;

        for(auto it : nums){
            totalsum += it;
        }

        if(totalsum < x)return -1;
        int target = totalsum - x;

        int i=0, j = 0;
        int sum = 0;
        int maxilen = INT_MIN;
        while(j < n){
            
            sum += nums[j];

            while(sum > target && i < n){
                sum -= nums[i];
                i++;
            }

            if(sum == target){
                maxilen = max(maxilen , j-i+1);
            }
            j++;
        }

        if(maxilen == INT_MIN)return -1;
        return n-maxilen;
    }
};