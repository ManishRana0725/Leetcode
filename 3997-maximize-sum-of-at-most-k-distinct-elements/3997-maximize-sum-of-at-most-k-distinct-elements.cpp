class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        set<int> choose ;
        int n = nums.size();
        sort(nums.begin() , nums.end());
        reverse(nums.begin() , nums.end());
        
        for(int i=0 ; i<n ; i++){
            if(choose.size() == k){
                break;
            }

            choose.insert(nums[i]);
        }

        vector<int> ans ;
        for(auto it : choose){
            ans.push_back(it);
            choose.erase(it);
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};