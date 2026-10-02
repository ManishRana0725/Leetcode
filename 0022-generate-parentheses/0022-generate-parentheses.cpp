class Solution {
public:
    vector<string> ans;
    void solve(int n , int count , string& s){
        if(s.size() == 2*n){
            if(count == 0){
                ans.push_back(s);
            }
            return ;
        }

        if(count < n){
            s.push_back('(');
            solve(n , count+1 , s);
            s.pop_back();
        }

        if(count > 0){
            s.push_back(')');
            solve(n , count-1 , s);
            s.pop_back();
        }

        return ;
    }
    vector<string> generateParenthesis(int n) {
        string s = "";
        solve(n , 0 , s);
        return ans;
    }
};