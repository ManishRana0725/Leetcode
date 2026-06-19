class Solution {
public:
    const long long INF=1e18;
    
    vector<long long> solve(int n,int l,int r,vector<long long> &dp,vector<long long> &prev){

        vector<long long> curr(n+1,-INF);
        deque<pair<int,long long>> dq;

        for(int i=1;i<=n;i++){
            int j=i-l;

            if(j>=0 && dp[j]> -INF){
                long long v=dp[j]-prev[j];

                while(!dq.empty() && dq.back().second<=v){
                    dq.pop_back();
                }

                dq.push_back({j,v});
            }

            while(!dq.empty() && dq.front().first<i-r){
                dq.pop_front();
            }

            curr[i]=curr[i-1];

            if(!dq.empty()){
                curr[i]=max(curr[i],dq.front().second + prev[i]);
            }
        }

        return curr;
        
    }

    long long maximumSum(vector<int>& nums, int m, int l, int r) {
        int n=nums.size();

        vector<long long> prev(n+1);

        for(int i=0;i<n;i++){
            prev[i+1]=prev[i]+nums[i];
        }

        vector<long long> dp(n+1,0);

        long long ans=-INF;

        for(int i=0;i<m;i++){
            dp=solve(n,l,r,dp,prev);
            ans=max(ans,dp[n]);
        }

        return ans;
    }
};