class Solution {
public:
    long long sumAndMultiply(int n) {
        
        int x = 0;
        int sum = 0;
        while(n > 0){
            int d = n %10;

            if(d > 0){
                x = x*10 + d;
                sum += d;
            }

            n = n/10;

        }
        string s = to_string(x);
        reverse(s.begin() , s.end());
        x = stoi(s);
        long long ans = (long long)x * (long long)sum;
        return ans;
    }
};