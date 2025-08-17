class Solution {
public:
    const int M = 1000000007;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();
        for (auto &q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            for (int idx = l; idx <= r; idx += k) {
                nums[idx] = (1LL * nums[idx] * v) % M;
            }
        }

        int result = 0;
        for(int i=0 ; i< n ; i++){
            result = result ^ nums[i];
        }
        return result;
    }
};