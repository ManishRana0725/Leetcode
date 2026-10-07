class Solution {
public:
    unordered_set<string> ans;
    int mincount = 0;

    bool checkvalid(string& s) {
        int count = 0;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(') {
                count++;
            }
            else if (s[i] == ')') {
                count--;
            }

            if (count < 0) {
                return false;
            }
        }

        return count == 0;
    }

    void solve(int i, string& s1, string& s, int removecount) {

        if (removecount > mincount) {
            return;
        }

        if (i == s.size()) {

            if (removecount == mincount && checkvalid(s1)) {
                ans.insert(s1);
            }

            return;
        }

        // Normal character
        if (s[i] != '(' && s[i] != ')') {

            s1.push_back(s[i]);

            solve(i + 1, s1, s, removecount);

            s1.pop_back();
        }

        else {

            // Take
            s1.push_back(s[i]);

            solve(i + 1, s1, s, removecount);

            s1.pop_back();

            // Remove
            solve(i + 1, s1, s, removecount + 1);
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        ans.clear();
        mincount = 0;

        int count = 0;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(') {
                count++;
            }
            else if (s[i] == ')') {
                count--;
            }

            if (count < 0) {
                mincount++;
                count = 0;
            }
        }

        mincount += count;

        string s1 = "";

        solve(0, s1, s, 0);

        vector<string> result(ans.begin(), ans.end());

        return result;
    }
};