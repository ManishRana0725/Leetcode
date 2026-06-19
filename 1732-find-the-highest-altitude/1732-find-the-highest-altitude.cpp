class Solution {
public:
    int largestAltitude(vector<int>& gain) {

        int n = gain.size();
        int higehestgain = 0 ;
        int ans = 0;
        for(int i=0 ; i<n ; i++){
            
            higehestgain += gain[i];
            ans = max(ans , higehestgain);
        }
        return ans;
    }
};