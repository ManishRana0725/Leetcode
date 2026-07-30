class Solution {
public:
    int minimumPushes(string word) {

        int n = word.size();

        int ans = 0;
        int count = 1;
        while(n > 0){
            if(n >= 8){
                ans += count * 8;
                count++;
                n -= 8;
            }else{
                ans += count * n;
                n = 0;
            }
        }

        return ans;
    }
};