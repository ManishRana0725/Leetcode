class Solution {
public:
    long long gcd(long long a, long long b){
        return b==0 ? a : gcd(b, a%b);
    }
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();

        vector<long long> prefix(n);

        long long mx = 0;

        for(int i=0;i<n;i++){
            mx = max(mx,(long long)nums[i]);
            prefix[i] = gcd(nums[i], mx);
        }

        sort(prefix.begin() , prefix.end());

        int l = 0 , r = n-1;
        long long sum = 0;
        while(l < r){
            sum += gcd(prefix[l] , prefix[r]);
            l++;
            r--;
        }
        return sum;

    }
};