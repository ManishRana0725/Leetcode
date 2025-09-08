class Solution {
public:
    vector<int> dp;
    bool isequal(vector<int>& v){
        int a = 0;
        
        for(int i=0 ; i<26 ;i++){
            if(v[i] > 0 && a == 0){
                a = v[i];
            }

            if(v[i] != a && v[i] > 0){
                return false;
            }
        }
        return true;
    }
    int solve(int ind , string & s){
        int n = s.size();  
        if(ind >= n)return 0; 

        if(dp[ind] != -1)return dp[ind];
        vector<int> mpp(26 , 0);
        int mini = INT_MAX;
        int ans = 0;
        for(int i = ind ; i<n ; i++){
            mpp[s[i]-'a']++;

            if(isequal(mpp)){
                ans = 1 + solve(i+1 , s);
            }
            mini = min(mini , ans);
        }

        return dp[ind] = mini;

    }
    int minimumSubstringsInPartition(string s) {
        int n = s.size();
        dp.resize(n+1 , -1);
        return solve(0 , s);
    }
};