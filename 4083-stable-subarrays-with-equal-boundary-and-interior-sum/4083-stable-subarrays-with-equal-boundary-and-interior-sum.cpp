class Solution {
public:
    long long countStableSubarrays(vector<int>& capacity) {

        int n = capacity.size();

        vector<long long> pre(n , 0);
        pre[0] = capacity[0];
        for(int i=1; i<n ;i++){
            pre[i] = pre[i-1] + capacity[i];                
        }

        map<pair<long long , long long> , int>mpp;

        mpp[{capacity[0] , pre[0]}]++;
        
        long long ans = 0;

        for(int r = 2; r < n ; r++){

            if(mpp.count({capacity[r] , pre[r-1] - capacity[r]})){
                ans += mpp[{capacity[r] , pre[r-1] - capacity[r]}];
            }

            mpp[{capacity[r-1] , pre[r-1]}]++;
        }
        return ans;
    }
};