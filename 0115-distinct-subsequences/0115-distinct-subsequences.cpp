class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i , int j , string& s , string& t ){
        int n = s.size();
        int m = t.size();
        
        if(j >= m)return 1;
        if(i >= n)return 0;
        
        if(dp[i][j] != -1)return dp[i][j];

        int ans = 0;

        if(s[i] == t[j]){
            ans += solve(i+1 , j+1 , s , t);
        }
        ans += solve(i+1 , j , s , t);

        return dp[i][j] = ans;
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        dp.assign(n , vector<int>(m , -1));

        return solve(0 , 0 , s, t);
    }
};