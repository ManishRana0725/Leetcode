class Solution {
public:
    int Mod = 1e9+7;
    int dp[2001];
    vector<int> prev;
    
    int solve(int i){
        
        if(i == 0)return 1;

        if(dp[i] != -1)return dp[i];

        int total = (2 * solve(i-1))%Mod;

        if(prev[i] != 0){
            int duplicate = solve(prev[i] -1);
            total = (total - duplicate + Mod)%Mod;
        }
        

        return dp[i] = total;
    }

    int distinctSubseqII(string s) {
        int n = s.size();

        memset(dp , -1 , sizeof(dp));
        prev.assign(n+1 , 0);
        vector<int> lastind(26 , 0);

        for(int i=1 ; i<=n ; i++){

            int ind = s[i-1] - 'a';

            prev[i] = lastind[ind];
            lastind[ind] = i;

        }

        return (solve(n)-1 + Mod ) % Mod;
    }
};