class Solution {
public:
    int minOperations(vector<int>& nums) {

        int n = nums.size();
        vector<int> flag ( n , 1);
         
        if(nums[n-1] == 1)flag[n-1] = 1;
        if(nums[n-1] == 0)flag[n-1] = 0;
       
        for(int i = n-2 ; i>= 0 ; i--){
            if(nums[i] == 0 && nums[i+1] == 1){
                flag[i] = 1;
            }
            if(nums[i] == 0 && nums[i] == nums[i+1]){
                if(flag[i+1] == 1){
                    flag[i] = -1;
                }else{
                    flag[i] = flag[i+1];
                }
            }
            
        }


        for(int i=0 ;i<n ;i++)cout<<flag[i] <<" ";
        int count = 0;
        
        for(int i=0 ;i<n ; i++){
        
            if(nums[i] == 0){
                if(flag[i] == -1)continue;
                if(flag[i] == 0){
                    count+=1 ;
                    break;
                }
                if(flag[i] == 1)count+=2;
                
            }
        }
        return count;
    }
};