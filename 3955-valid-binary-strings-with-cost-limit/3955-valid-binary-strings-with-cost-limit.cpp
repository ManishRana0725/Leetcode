class Solution {
public:
    vector<string> ans;
    void solve(int i , int n , int k , int cost , string& s , bool prev){
        if(i == n){
            if(cost <= k){
                ans.push_back(s);
                return;
            }else{
                return;
            }
        }
        if(!prev){
            s.push_back('1');
            solve(i+1 , n , k , cost+i , s , true);
            s.pop_back();
        }
        s.push_back('0');
        solve(i+1 , n , k , cost , s , false);
        s.pop_back();
        return;
    }
    vector<string> generateValidStrings(int n, int k) {
        string s = "";
        solve(0 , n , k , 0 , s , false);

        return ans;
    }
};