class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
       int n = nums.size();

        // Find number of digits
        int d = to_string(nums[0]).size();

        long long ans = 0;

        // Process each digit position
        for (int pos = 0; pos < d; pos++) {
            vector<int> cnt(10, 0); // digit frequency at this position

            for (int num : nums) {
                string s = to_string(num);
                cnt[s[pos] - '0']++;
            }

            long long totalPairs = 0;
            long long count_sum = 0;
            for(int c : cnt){
                count_sum += c;
            }
            for (int c : cnt) {
                totalPairs += 1LL * c * (count_sum - c);
                count_sum = count_sum - c;
            }

            ans += totalPairs ; // each pair counted twice
        }
        return ans;
    }
};