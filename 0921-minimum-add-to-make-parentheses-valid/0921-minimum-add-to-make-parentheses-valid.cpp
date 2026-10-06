class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();

        int count = 0;
        int score = 0;
        for(int i=0 ; i<n ;i++){

            if(s[i] == '('){
                count++;
            }else{
                count--;
            }

            if(count < 0){
                score++;
                count = 0;
            }
        }

        score += count;

        return score;
    }
};