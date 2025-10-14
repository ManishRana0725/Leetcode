class Solution {
public:
    int reduce(int xor1 , vector<int>& bit , int x){
        int xor2 = xor1;
        for(int i=0 ; i<32 ; i++){
            int x_i = (x >> i) & 1;
            if(x_i == 1){
                bit[i]--;
                if(bit[i] == 0){
                    xor2 = xor2 & ~(1 << i);
                }
            }
        }
        return xor2;
    }
    void add( vector<int>& bit , int x){
        for(int i=0 ; i<32 ; i++){
            int x_i = (x >> i) & 1;
            if(x_i == 1){
                bit[i]++;
            }
        }
        return;
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int xor1 = 0;
        vector<int> bit(32 , 0);
        int ans = INT_MAX;
        int l =0; 
        int r = 0;
        while(r < n){

            add( bit , nums[r]);
            xor1 = xor1 | nums[r];
            
            // if(xor1 >= k){
            //     ans = mini(ans , r-l +1 );
            // }
            
            while(l <= r && xor1 >= k){
                ans = min(ans , r-l +1 );
                xor1 = reduce(xor1 , bit , nums[l]);
                l++;
                
            }

            r++;
            
        }
        if(ans == INT_MAX)return -1;
        return ans;
    }
};