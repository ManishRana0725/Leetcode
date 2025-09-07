class Solution {
public:
    int minOperations(string s) {
        vector<int> mpp(26 , 0);
        int n = s.size();
        for(int i=0 ; i<n ;i++){
            mpp[s[i]-'a']++;
        }

        int count = 0;
        for(int i=1; i<26 ; i++){
            if(mpp[i] > 0 && i != 25){
                mpp[i+1] += mpp[i];
                count += 1;
            }
            if(i == 25 && mpp[i] > 0){
                count++;
            }
            
        }
        return count;
    }
};