class Solution {
public:
    int maxLen = 1;
    bool checkHamming(string& s1 , string& s2){
        int diff = 0;
        for(int i=0 ; i<s1.size() ; i++){
            if(s1[i] != s2[i])diff++;
        }
        return (diff <= 1);
    }
    vector<string> solve(int i  , vector<string>& words , vector<int>& groups , vector<vector<string>>& dp){
        int n = words.size();

        if(i >= n)return {};
        
        if(dp[i].size() != 1)return dp[i];
       
        

        for(int j=0 ; j<i ; j++){
            if(words[i].size() == words[j].size()  && checkHamming(words[i] , words[j]) && groups[i] != groups[j]){

                if(dp[j].size()+1 > dp[i].size()){
                    dp[i] = dp[j];
                    dp[i].push_back(words[i]);
                    maxLen = max(maxLen , int(dp[i].size()));
                }
            }
        }

        auto res = solve(i+1 , words , groups , dp);
        return dp[i];
    }
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<vector<string>> dp(n);

        for(int i=0 ; i<n ;i++){
            dp[i].push_back(words[i]);
        }

        auto res = solve(0 , words , groups , dp);

        vector<string> longest;

        for(int i=0 ; i<n ; i++){
            if(dp[i].size() == maxLen){
                longest = dp[i];
                break;
            }
        }
        return longest;
    }
};


