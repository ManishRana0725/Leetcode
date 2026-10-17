class Solution {
public:
    static int digitsum(int num){
        int sum = 0;
        while(num > 0){
            int d = num%10;
            sum += d;
            num = num/10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<int> sortednum = nums;
        unordered_map<int , int> mpp;

        auto lambda = [](int num1 , int num2){

            int sum1 = digitsum(num1);
            int sum2 = digitsum(num2);

            if(sum1 != sum2){
                return sum1 < sum2;
            }

            return num1 < num2;
        };

        sort(sortednum.begin() , sortednum.end() , lambda);

        for(int i=0 ; i<n ; i++){
            mpp[nums[i]] = i;
        }
        

        int ans = 0 ;
        for(int i=0 ; i<n ; i++){
            int excepted = sortednum[i];
            int original = nums[i];

            if(excepted == original){
                continue;
            }
            int ind = mpp[excepted];
                
            swap(nums[i], nums[ind]);

            mpp[nums[ind]] = ind;
            mpp[nums[i]] = i;

            ans++;
        }
        return ans;

    }
};