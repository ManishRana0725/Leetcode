class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        string t = s;
        sort(t.begin() , t.end());

        if(s == t)return 0;

        if(n == 2)return -1;


        if(t[0] == s[0] || t[n-1] == s[n-1])return 1;
            
        else{
            int a = -1 , b = -1;

            for(int i=0 ; i<n ; i++){
                if(a == -1 && s[i] == t[0]){
                    a = i;
                }
                if(s[i] == t[n-1]){
                    b = i;
                }
            }

            if(b == 0 && a == n-1)return 3;
            else{
                return 2;
            }
        }
    }
};