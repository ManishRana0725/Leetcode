class Solution {
public:
    string minimizeStringValue(string s) {
        vector<int> freq(26, 0);
        vector<bool> used(26, false);
        int usedCount = 0;
        string t = "";
        // Mark existing characters
        for (char c : s) {
            if (c != '?') {
                freq[c - 'a']++;
                if (!used[c - 'a']) {
                    used[c - 'a'] = true;
                    usedCount++;
                }
            }
        }

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '?') {
                char chosen;
                if (usedCount < 26) {
                    // Pick smallest unused letter
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (!used[c - 'a']) {
                            chosen = c;
                            used[c - 'a'] = true;
                            usedCount++;
                            break;
                        }
                    }
                } else {
                    // All used → pick min frequency letter
                    int minFreq = INT_MAX;
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (freq[c - 'a'] < minFreq) {
                            minFreq = freq[c - 'a'];
                            chosen = c;
                        }
                    }
                }

                t.push_back(chosen);
                freq[chosen - 'a']++;
            }
        }

        sort(t.begin() , t.end());
        int i=0;
        for(auto& it : s){
            if(it == '?'){
                it = t[i];
                i++;
            }
        }
        return s;
    }
};