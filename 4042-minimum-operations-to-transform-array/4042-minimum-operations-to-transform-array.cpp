class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        long long ans = 0;
        int last = nums2[n];
        int lastValue = INT_MAX;
        
        for(int i=0; i<n ; i++){
            int d1 = nums1[i];
            int d2 = nums2[i];
            int add = abs(d1 - d2);
            ans += add;
            if(last == d1){
                lastValue = 0;
            }
            if((last >= d1 && last <= d2)  || (last >= d2 && last <= d1)){
                lastValue = 0;
            }else{
                lastValue = min(lastValue , abs(nums1[i] - last));
                lastValue = min(lastValue , abs(nums2[i] - last));
            }
        }

        ans += lastValue ;
        ans++;
        return ans;
    }
};