class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        
        int n = nums1.size();
        int min_val = nums1[0];
        
        for (int i = 1; i < n; ++i) {
            if (nums1[i] < min_val) {
                min_val = nums1[i];
            }
        }
        
        if (min_val % 2 != 0) {
            return true;
        }

        for (int x : nums1) {
            if (x % 2 != 0) {
                return false;
            }
        }

        return true;
    }
};