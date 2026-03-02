class Solution {
public:
    int countCompleteSubstrings(string s, int k) {

        int n = s.size();
        int count = 0;

        
        for(int targetDistinct = 1; targetDistinct <= 26; targetDistinct++) {

            int windowSize = targetDistinct * k;
            if(windowSize > n) break;

            vector<int> mpp(26, 0);
            int distinct = 0;
            int ktimes = 0;
            int l = 0;

            for(int r = 0; r < n; r++) {

                if(r > 0 && abs(s[r] - s[r-1]) > 2) {
                    mpp.assign(26, 0);
                    distinct = 0;
                    ktimes = 0;
                    l = r;
                }

                int idx = s[r] - 'a';
                mpp[idx]++;

                if(mpp[idx] == 1)
                    distinct++;

                if(mpp[idx] == k)
                    ktimes++;

                if(mpp[idx] == k + 1)
                    ktimes--;

                while(r - l + 1 > windowSize) {
                    int leftIdx = s[l] - 'a';

                    if(mpp[leftIdx] == k)
                        ktimes--;

                    if(mpp[leftIdx] == k + 1)
                        ktimes++;

                    mpp[leftIdx]--;

                    if(mpp[leftIdx] == 0)
                        distinct--;

                    l++;
                }

                // Check valid substring
                if((r - l + 1) == windowSize && distinct == targetDistinct && ktimes == targetDistinct) {
                    count++;
                }
            }
        }

        return count;
        
    }
};