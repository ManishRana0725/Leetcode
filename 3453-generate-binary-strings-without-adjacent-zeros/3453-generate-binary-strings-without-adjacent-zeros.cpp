class Solution {
public:
    vector<string> ans;
    void solve(int i , int n , int prev , string& s){

        if(i == n)return ans.push_back(s);

        if(i - prev == 2 ){
            s+="1";
            solve(i+1 , n , i , s);
            s.pop_back();
        }
        else{
            s+="1";
            solve(i+1 , n , i , s);
            s.pop_back();
            s+="0";
            solve(i+1 , n , prev , s);
            s.pop_back();
        }
        
    }
    vector<string> validStrings(int n) {
        string s = "";
        solve(0 , n , -1 , s);
        return ans;
    }
};