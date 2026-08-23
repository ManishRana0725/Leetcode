class Solution {
public:

    vector<int> getPrimeFactors(int num) {
        vector<int> factors;

        for (int i = 2; i * i <= num; i++) {

            if (num % i == 0) {

                factors.push_back(i);

                while (num % i == 0) {
                    num /= i;
                }
            }
        }
        
        if (num > 1) {
            factors.push_back(num);
        }

        return factors;
    }

    int longestSubarray(vector<int>& nums, int k) {

        int n = nums.size();

        unordered_map<int, int> freq;

        int l = 0;
        int r = 0;
        int distinct = 0;
        int ans = 0;

        while(r < n){

            vector<int> factors = getPrimeFactors(nums[r]);

            for (int p : factors) {
                if (freq[p] == 0) {
                    distinct++;
                }
                freq[p]++;
            }

            while (distinct > k) {

                vector<int> leftFactors =
                    getPrimeFactors(nums[l]);

                for (int p : leftFactors) {

                    freq[p]--;

                    if (freq[p] == 0) {
                        distinct--;
                    }
                }

                l++;
            }

            ans = max(ans, r - l + 1);

            r++;
        }

        return ans;
    }
};