class Solution {
public:
    vector<bool> isprime;
    vector<int> prime(int n){
        
        vector<int> ans;
        for(int i=2 ; i<=n ; i++){
            if(isprime[i]){
                ans.push_back(i);
                int j = 2*i;
                while(j <= n ){
                    isprime[j] = false;
                    j+=i;
                }
            }
        }
        return ans;
    }
    int largestPrime(int n) {
        isprime.assign(n+1 , true);
        vector<int>primenum = prime(n);

        int sum = 0;
        int ans = 0;
        for(int i=0 ; i<primenum.size() ; i++){
            sum += primenum[i];

            if( sum <= n && isprime[sum]){
                ans = sum;
            }
            if(sum > n){
                sum -= primenum[i];
                break;
            }
        }

        return ans;
    }
};