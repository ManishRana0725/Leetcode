class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        int n = nums.size();

        priority_queue<pair<long long , int>> pq;
        vector<long long> ans ;
        unordered_map<int , long long> mpp;
        for(int i=0; i<n ; i++){
            if(mpp.find(nums[i]) != mpp.end())mpp[nums[i]] += freq[i];
            else{
                mpp[nums[i]] = freq[i];
            }
            pq.push({mpp[nums[i]] , nums[i]});
            while(pq.top().first != mpp[pq.top().second]){
                pq.pop();       // removing if we find the value wrong acc to mpp ;
            }
            ans.push_back(pq.top().first);  // always store the new value prev value will get removed
        }
        return ans;

    }
};