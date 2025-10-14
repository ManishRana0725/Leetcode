class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int n = possible.size();
        int ans = -1;

        vector<int> bob(n , 0);
        bob[n-1] = (possible[n-1] == 1) ? 1 : -1 ;
        for(int i=n-2; i>=0 ;i--){
            if(possible[i] == 1){
                bob[i] = bob[i+1] +1;
            }else{
                bob[i] = bob[i+1] -1;
            }
        }
        int alice =0;
        for(int i=0 ; i<n-1 ;i++){
            if(possible[i] == 1){
                alice++;
            }else{
                alice--;
            }

            if(alice > bob[i+1]){
                ans = i+1;
                break;
            }
        }
        return ans;
    }
};