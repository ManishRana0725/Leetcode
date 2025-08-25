class Solution {
public:
    const int M = 1000000007;
    int valueAfterKSeconds(int n, int k) {
        vector<int> v(n , 1);
        while(k--){
            for(int i=1 ; i<n ;i++){
                v[i]  = (v[i-1] + v[i]) % M;
            }
        }
        return v[n-1];
    }
};