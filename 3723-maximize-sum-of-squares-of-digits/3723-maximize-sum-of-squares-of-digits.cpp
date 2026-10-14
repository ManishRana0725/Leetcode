class Solution {
public:
    string maxSumOfSquares(int num, int sum) {

        string result = "";
        
        if (9*num >= sum){
            
            for (int i = 0; i < num; i++) {
                int d = min(9, sum);
                
                result += to_string(d);
                sum -= d;
            }
        
            return result;
        }
        else{
            return result;
        }
        
        
    }
};