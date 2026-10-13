class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        for(int i=0; i<n ;i++){
            if(nums[i] < 0){
                nums[i] = nums[i] * -1;
            }
        }

        sort(nums.begin() , nums.end());
        int i=0;
        int j = n-1;
        bool flag = true;
        long long score = 0;
        while(i <= j){

            if(flag){
                score += (nums[j]*nums[j]);
                j--;
                flag = !flag;
            }else{
                score -= (nums[i]*nums[i]);
                i++;
                flag = !flag;
            }
        
        }
        return score;
    }
};