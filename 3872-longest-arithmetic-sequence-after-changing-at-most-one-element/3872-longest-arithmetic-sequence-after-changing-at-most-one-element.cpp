class Solution {
public:
    int longestArithmetic(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int , vector<pair<int , int>>> mpp;
        int l= 0 ; 
        int diff = nums[1] - nums[0];
        for(int i = 1;  i<n ;i++){

            if(nums[i] - nums[i-1] != diff){
                mpp[diff].push_back({l , i-1 });
                diff = nums[i] - nums[i-1];
                l = i-1;
            }
        }
        mpp[diff].push_back({l , n-1 });

        int ans = 2;

        for(auto it : mpp){ // check for i+2 
            int diff = it.first;

            vector<pair<int ,int>> v = it.second;

            for(int i=0 ; i<v.size() ;i++){
                int l = v[i].first;
                int r = v[i].second;
                int len = r - l +1;
                ans = max(ans , len);// normal len

                if(l != 0 || r != n-1)ans = max(ans , len+1); //  len when 1 more is changed

                // when a , b , c , d , e so a , b ,c  form a subarray and by changing d -> a, b , c ,d ,e form subarray   for both direction 
                if(l > 1 ){
                    if((nums[l] - nums[l-2])%2 == 0 && (nums[l] - nums[l-2])/2 == diff){
                        ans = max(ans , len+2);
                    }
                }
                if(r < n-2){
                    if((nums[r+2] - nums[r])%2 == 0 && (nums[r+2]-nums[r])/2 == diff){
                        ans = max(ans , len+2);
                    }
                }
            }
            
        }

        for(auto it : mpp){
            
            int d = it.first;

            vector<pair<int,int>> v = it.second;

            for(int i=0 ; i<v.size()-1 ; i++){
                int l1 = v[i].first;
                int r1 = v[i].second;

                int l2 = v[i+1].first;
                int r2 = v[i+1].second;
            
            
                int len1 = r1 - l1 +1;
                int len2 = r2 - l2 +1;

                if(r1+2 == l2){

                    int diff = nums[l2] - nums[r1];
                    if(diff%2 == 0 && diff/2 == d){
                        ans = max(ans , len1 + len2 + 1 );
                    }
                
                }
            }
        }
        return ans;
    }
};