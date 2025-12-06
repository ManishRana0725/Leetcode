class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        int mini = nums[0] - k;
        int maxi = nums[n-1]+k;
        int curr = mini ;
        unordered_map<int , int> mpp;
        for(int i=0 ; i<n ;i++){

            int d = nums[i] - k;

            curr = max(d , curr);

            if(curr <= nums[i]+k){
                mpp[curr]++;
                curr++;
            }else{
                mpp[nums[i]]++;
            }
        }

        return mpp.size();

        

    }
};