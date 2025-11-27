class Solution {
public:
    int maxBalancedSubarray(vector<int>& nums) {
        int n = nums.size();
        map<pair<int , int> , int> mpp; 
        int odd = 0;
        int even = 0;
        int prexor = 0;
        
        int diff = odd - even;
        mpp[{0 , 0}] = -1;
        int len = 0;
        for(int i=0 ; i<n ;i++){
            if(nums[i] & 1){
                odd++;
            }else{
                even++;
            }
            int diff = odd - even;
            
            prexor ^= nums[i];
            auto p = make_pair(prexor , diff);
            if(mpp.find(p) != mpp.end()){
                len = max(len , i - mpp[p]);
            }else{
                mpp[p] = i;
            }
            

        }

        return len;

    }
};