class Solution {
public:
    const int M = 1000000007;
    vector<int> dp;
    int solve(int i  , string& s , int k ){

        if(i >= s.size())return 1;
        
        if(dp[i] != -1)return dp[i];
        int res = 0;
        long long num = 0;
        for(int end = i ; end < s.size() ; end++){
            num = num*10 + (s[end]-'0');
            // string str = s.substr(i , end - i + 1 );
            // int a = stoi(str);
            if(num <= k && num > 0){
                res = (res + solve(end+1 , s , k ))%M;
            }else{
                break;
            }
        }

        return dp[i] =res;
    }
    int numberOfArrays(string s, int k) {
        int n = s.size();
        dp.resize(n+1 , -1);
        return solve(0 , s , k);
    }
};