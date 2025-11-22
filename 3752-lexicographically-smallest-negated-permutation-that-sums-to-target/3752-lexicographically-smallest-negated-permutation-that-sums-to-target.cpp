class Solution {
public:
    vector<int> lexSmallestNegatedPerm(int n, long long target) {
        
        long long sum = 1LL * n * (n + 1) / 2;

        if(target > sum || target < -sum || (sum - target)%2 == 1){
            return {};
        }
        vector<bool> neg(n+1 , false);
        for(int i=n ; i>= 1 ; i--){

            long long d = sum - target;
            if(2*i <= d){
                neg[i] = true;
                sum -= 2*i;
            }
        }

        vector<int> ans;
        for(int i=1; i<=n ; i++){
            if(neg[i]){
                ans.push_back(-i);
            }else{
                ans.push_back(i);
            }
        }
        sort(ans.begin() , ans.end());
        return ans;
    }
};