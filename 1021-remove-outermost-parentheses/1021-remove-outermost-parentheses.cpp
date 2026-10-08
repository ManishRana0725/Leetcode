class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();


        vector<string> store;
        
        string s1 = "";
        int count = 1;
        for(int i=1  ; i<n ; i++){

            if(s[i] == '('){
                count++;
            }
            else{
                count--;
            }

            if(count == 0){
                store.push_back(s1);
                i++;
                count = 1;
                s1 = ""; 
            }else{
                s1 += s[i];
            }

        }

        string ans = "";

        for(auto it : store){
            ans += it;
        }
        return ans;
    }
};