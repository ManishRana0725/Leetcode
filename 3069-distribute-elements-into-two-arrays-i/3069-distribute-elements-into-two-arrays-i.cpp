class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> arr1 , arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        for(int i=2 ; i<n ;i++){
            
            int a = arr1.back();
            int b = arr2.back();
            if(a > b){
                arr1.push_back(nums[i]);
            }else{
                arr2.push_back(nums[i]);
            }
        }

        vector<int>ans;
        int i=0;
        while(arr1.size() > i){
            ans.push_back(arr1[i]);
            i++;
        }
        i=0;
        while(arr2.size() > i){
            ans.push_back(arr2[i]);
            i++;
        }

        return ans;
    }
};