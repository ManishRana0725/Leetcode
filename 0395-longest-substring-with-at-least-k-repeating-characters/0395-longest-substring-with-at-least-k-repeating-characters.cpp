class Solution {
public:

    int longestSubstring(string s, int k) {
        int n = s.size();
        vector<int> mpp(26 , 0);
        for(int i=0 ; i<n ;i++){
            mpp[s[i]-'a']++;
        }

        for(int i=0 ; i<n ; i++){

            if(mpp[s[i]-'a'] < k){
                int left = longestSubstring(s.substr(0 , i) , k);
                int right = longestSubstring(s.substr(i+1) , k);
                return max(left , right);
            }
        }

        return n;
    }
};