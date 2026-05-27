class Solution {
public:
    int numberOfSpecialChars(string s) {
        int n = s.size();

        vector<int> firstupper (26 , INT_MAX);
        vector<int> lastlower (26 , -1);
        int count = 0;
        for(int i=0 ; i<n ;i++){
            int ind = s[i]-'a';
            if(s[i] >= 97){
                lastlower[s[i]-'a'] = i;
            }else{
                firstupper[s[i]-'A'] = min(firstupper[s[i]-'A'] , i);
            }
        }

       

        for(int i=0 ; i < 26 ; i++){
            if( lastlower[i] != -1 && firstupper[i] != INT_MAX && firstupper[i] > lastlower[i]){
                count++;
            }
        }
        return count;
    }
};