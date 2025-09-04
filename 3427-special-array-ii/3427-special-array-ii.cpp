class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n= nums.size();
        vector<int> parity(n);
        for(int i=0 ;i<n-1 ;i++){

            if(nums[i]%2 != nums[i+1]%2){
                parity[i] = 0;
            }else{
                parity[i] = -1;
            }
        }

        parity[n-1] = 0;
        cout<<parity[0]<<" ";
        for(int i=1 ; i<n ;i++){
            parity[i] += parity[i-1];
            cout<<parity[i]<<" ";
        }
        vector<bool> ans;
        for(auto it : queries){
            int l = it[0];
            int r = it[1];
            if(l == r){
                
                
                ans.push_back(true);
                
                continue;
            }
            int sum = parity[r-1] - (l > 0 ? parity[l-1] : 0 );
            if(sum < 0)ans.push_back(false);
            else{
                ans.push_back(true);
            }
        }
        return ans;
    }
};