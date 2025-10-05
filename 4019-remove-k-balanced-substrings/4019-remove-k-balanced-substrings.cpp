class Solution {
public:
    string removeSubstring(string s, int k) {
        vector<pair<char, int>> st;

        for (char c : s) {
            if (!st.empty() && st.back().first == c) {
                st.back().second++;
            } else {
                st.push_back({c, 1});
            }

         
            while (st.size() >= 2) {
                auto [ch1, cnt1] = st[st.size() - 2];
                auto [ch2, cnt2] = st[st.size() - 1];
                if (ch1 == '(' && ch2 == ')' && cnt1 >= k && cnt2 >= k) {
                    st[st.size() - 2].second -= k;
                    st[st.size() - 1].second -= k;
                    if (st[st.size() - 2].second == 0) st.erase(st.end() - 2);
                    if (!st.empty() && st.back().second == 0) st.pop_back();
                } else break;
            }
        }

        
        string res;
        for (auto [ch, cnt] : st) res.append(cnt, ch);
        return res;
    }
};