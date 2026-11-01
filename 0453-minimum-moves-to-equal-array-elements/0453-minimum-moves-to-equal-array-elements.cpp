class Solution {
public:
    int minMoves(vector<int>& nums) {
        
        int mini = INT_MAX;
        int n = nums.size();
        for(int i=0 ; i<n ;i++){
            mini = min(mini , nums[i]);
        }

        int count = 0;

        for(int i=0 ; i<n ; i++){
            count += abs(mini - nums[i]);
        }
        return count;
    }
};