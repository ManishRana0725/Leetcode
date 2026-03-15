class Solution {
public:
    int longestArithmetic(vector<int>& nums) {
        int n = nums.size();
        // if (n <= 2) return 0;

        // int ans = 2;

        // vector<int> left(n, 2);
        // vector<int> right(n, 2);
        
        // for(int i=2; i<n; i++) {
        //     if (nums[i-1]-nums[i-2] == nums[i]-nums[i-1]) {
        //         left[i] = left[i-1] + 1;
        //     }
        // }

        // for(int i=n-3; i>=0; i--) {
        //     if (nums[i+2]-nums[i+1] == nums[i+1] - nums[i]) {
        //         right[i] = right[i+1] + 1;
        //     }
        // }
     
        // for(int i=0; i<n; i++) {
        //     ans = max(ans, max(left[i], right[i]));
            
        //     if (i == 0) {
        //         ans = max(ans, 1+right[i+1]);
        //     }
        //     else if (i == n-1) {
        //         ans = max(ans, 1+left[i-1]);
        //     }
        //     else  {
        //         ans = max(ans, 1+left[i-1]);
        //         ans = max(ans, 1+right[i+1]);
        //         if (((nums[i+1] - nums[i-1]) % 2) == 0) {
        //             int req = (nums[i+1]-nums[i-1])/2;
        //             int leftLen = 1, rightLen = 1;
        //             if (i >= 2 && (nums[i-1]-nums[i-2] == req)) {
        //                 leftLen = left[i-1];
        //             }

        //             if (i < n-2 && (nums[i+2]-nums[i+1] == req)) {
        //                 rightLen = right[i+1];
        //             }

        //             ans = max(ans, 1 + leftLen + rightLen);
        //         }
        //     }
        // }

        // return ans;

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