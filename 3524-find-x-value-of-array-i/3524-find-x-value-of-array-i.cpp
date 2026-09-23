class Solution {
public:
    
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();

        vector<long long > result(k , 0) , prev(k , 0);

        for(int i=0 ; i<n ; i++){

            vector<long long> curr(k , 0);
            int rem = nums[i] % k;
            curr[rem]++;

            for(int j=0 ; j<k ; j++){

                curr[(j*rem)%k] += prev[j];
            }

            for(int j =0 ; j<k ; j++){
                result[j] += curr[j];
            }

            prev = curr;
        }

        return result;

    }
};