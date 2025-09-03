class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        unordered_map<int,int> x_occ;
        int n = nums.size();
        int occ = 0 ;
        for(int i=0 ; i<n ;i++){
            if(nums[i] == x){
                occ++;
                x_occ[occ] = i;
            }
        }

        vector<int> ans;
        for(int i=0 ; i<queries.size() ; i++){
            if(x_occ.find(queries[i]) != x_occ.end()){
                ans.push_back(x_occ[queries[i]]);
            }else{
                ans.push_back(-1);
            }
        }
        return ans;
    }
};