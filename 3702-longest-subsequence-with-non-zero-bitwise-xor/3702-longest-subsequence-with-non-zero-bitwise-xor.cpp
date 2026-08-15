class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int xor1 = 0;
        
        int nonzero = 0;
        for(auto it : nums){
            if(it != 0)nonzero++;
            xor1 = xor1 ^ it;
        }

        int ans = xor1;
        if(xor1 != 0)return n;

        
        if(nonzero){
            return n-1;
        }
        
        return 0;
    }
};