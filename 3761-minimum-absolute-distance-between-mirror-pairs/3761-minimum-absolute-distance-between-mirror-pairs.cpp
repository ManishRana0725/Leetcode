class Solution {
public:
    int rev(int x){
        int num = 0;

        while(x > 0){
            int d = x%10;
            x = x/10;
            num = num*10 + d;

        }

        return num;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int , vector<int>> reversed;
        int n = nums.size();
        int ans = INT_MAX;
        for(int i=0 ; i< n ; i++){

            if(reversed.count(nums[i])){
                int d = reversed[nums[i]].back();
                int diff = abs(i - d);
                ans = min(ans , diff);
            }
            
            int a = rev(nums[i]);
            reversed[a].push_back(i);

            
        }
        if(ans == INT_MAX)return -1;
        return ans;
    }
};