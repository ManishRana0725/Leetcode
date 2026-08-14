class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();

        int ans = 0;

        for(int i=0 ; i<n; i++){
            vector<int> mpp(26 , 0);
            for(int j = i ; j<n ; j++){

                if(mpp[s[j]-'a'] < 2){
                    mpp[s[j]-'a']++;
                    ans = max(ans , j - i +1);
                }else{
                    break;
                }
            }
        }
        return ans;
    }
};