class Solution {
public:
    int getLength(vector<int>& nums) {
        
        int n = nums.size();
        int ans = 1;


        for(int i=0 ; i<n ; i++){
            unordered_map<int , int> mpp ;
            vector<int> freq(n+1 );

            int maxi = 0 ;
            int maxicount = 0;


            for(int j = i ; j<n ; j++){

                if(mpp[nums[j]]){
                    freq[mpp[nums[j]]]--;
                }
                mpp[nums[j]]++;
                freq[mpp[nums[j]]]++;
                

                if(mpp[nums[j]] > maxi){
                    maxi = mpp[nums[j]];
                    maxicount = 1;
                }
                else if(mpp[nums[j]] == maxi){
                    maxicount++;
                }


                int dis = mpp.size();

                if(dis == 1){
                    ans = max(ans , j - i +1);
                }else if(maxi % 2 == 0 && maxicount < dis && freq[maxi/2] == dis - maxicount){
                    ans = max(ans , j-i +1);
                }
            }

        }
        return ans;
    }
};