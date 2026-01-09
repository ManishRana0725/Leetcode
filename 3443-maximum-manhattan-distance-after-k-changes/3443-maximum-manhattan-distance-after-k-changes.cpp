class Solution {
public:
    int maxDistance(string s, int k) {

        int n = s.size();

        unordered_map<char , int> mpp;
        int maxi = 0;
        mpp['N'] = 0 , mpp['S'] = 0 , mpp['E'] = 0 , mpp['W'] = 0;
        for(int i=0 ; i<n ; i++ ){
            int times = k;
            mpp[s[i]]++;
            
            int ns = min(mpp['N'] , mpp['S']);
            int ew = min(mpp['E'] , mpp['W']);

            times = min(k , ns + ew);
            maxi = max(maxi , abs(mpp['N'] - mpp['S']) + abs(mpp['E'] - mpp['W']) + 2*times);   
           
        }
        return maxi;
    }
};