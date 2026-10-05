class Solution {
public:
    
    int scoreOfParentheses(string s) {
        int n = s.size();
        vector<int> v;

        int score = 0;
        for(int i=0 ; i<n ; i++){

            if(s[i] == '('){
                v.push_back(score);
                score=0;
            }else{
                if(s[i-1] == '(' ){
                    score = v.back()+1;
                }else{
                    score = v.back() + (2*score);

                }
                v.pop_back();
            }
        }    
        return score;

    }
};