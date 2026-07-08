class Solution {
public:
    int solve(int i , string&s1 , string& s2){
        int n = s1.size();

        if(i >= n)return 0;

        int ans = 0;
        if( (s1[i] == '0' && s2[i] == '0') || (s1[i] == '1' && s2[i] == '1')){
            ans = solve(i+1 , s1 , s2);
        }
        else{
            if(s1[i] == '0'){
                ans +=  1 + solve(i+1 , s1 , s2); 
            }else{
                if(i == n-1){
                    ans += 2 + solve(i+1 , s1 , s2);
                }else{
                    if(s1[i+1] == '1'){
                        s1[i+1] = '0';
                        ans += 1 + solve(i+1 , s1 , s2);
                    }else{
                        ans += 2 + solve(i+1 , s1 , s2);
                    }
                }
            }
        }
        

        return ans;

    }
    int minOperations(string s1, string s2) {
        int n = s1.size();

        if(n == 1 ){
            if(s1[0] == '0' && s2[0] == '0' || s1[0] == '1' && s2[0] == '1')return 0;
            else if(s1[0] == '0' && s2[0] == '1')return 1;
            else{
                return -1;
            }
        }


        return solve(0 , s1 , s2);
    }
};