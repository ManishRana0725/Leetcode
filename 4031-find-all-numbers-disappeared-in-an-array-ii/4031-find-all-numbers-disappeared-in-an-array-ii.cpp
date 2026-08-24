class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        int n = nums.size();

        unordered_map<int , int> mpp;
        vector<vector<int>> ans;
        for(auto it : nums)mpp[it]++;

        int last = -1;
        for(int i=lower ; i<= upper ; i++){

            if(!mpp.count(i)){
                int j = i;
                int last = -1;
                while(!mpp.count(j) && j <= upper){
                    last = j;
                    j++;
                }
                ans.push_back({i , last});
                i = j;
            }
            
        }
        return ans;
    }
};