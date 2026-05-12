class Solution {
public:
    long long minArraySum(vector<int>& nums) {

        int maxi = *max_element(nums.begin(), nums.end());
        
        int n = nums.size();
       
        vector<int> freq(maxi+1 , 0);
        
        for(int i=0 ; i<n ; i++){
            freq[nums[i]]++;
        }
        vector<int> best(maxi+1 , -1);

        for(int i=1 ; i<= maxi ; i++){
            
            if(freq[i] == 0)continue;

            for(int d = i ; d <= maxi ; d+=i){

                if(freq[d] > 0 && best[d] == -1 ){
                    best[d] = i;
                }
            }
        }

        long long ans = 0;

        for (int x : nums)
            ans += best[x];

        return ans;

    }
};