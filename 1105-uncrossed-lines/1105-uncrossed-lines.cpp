class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i , int j , vector<int>& nums1, vector<int>& nums2){
        int n = nums1.size();
        int m = nums2.size();
        if(i >= n || j >= m)return 0;

        if(dp[i][j] != -1)return dp[i][j];
        int res = 0;
        if(nums1[i] == nums2[j]){
            res = 1+solve(i+1 , j+1 , nums1 , nums2);
        }
        res = max(res , solve(i+1 , j , nums1 , nums2));
        res = max(res , solve(i , j+1 , nums1 , nums2));

        return dp[i][j] = res;
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        dp.resize(n+1 , vector<int>(m+1 , -1));
        return solve(0 , 0 , nums1 , nums2);
    }
};