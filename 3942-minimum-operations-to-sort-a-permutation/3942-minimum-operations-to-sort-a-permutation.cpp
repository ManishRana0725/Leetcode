class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        int pos0 = 0;
        while (nums[pos0] != 0) pos0++;

        int ans = INT_MAX;

        // Case 1: rotation of sorted array
        bool rotationSorted = true;

        for (int i = 0; i < n; i++) {
            if (nums[(pos0 + i) % n] != i) {
                rotationSorted = false;
                break;
            }
        }

        if (rotationSorted) {
            ans = min(ans, min(pos0 , n-pos0+2));
        }

        
        bool rotationReversed = true;

        for (int i = 0; i < n; i++) {
            if (nums[(pos0 - i + n) % n] != i) {
                rotationReversed = false;
                break;
            }
        }

        if (rotationReversed) {
            int k = n-1-pos0;
            int op1 = k+1;
            int op2 = n - k+1;
            ans = min({ans , op1 , op2});
        }

        return ans == INT_MAX ? -1 : ans;
    }
};