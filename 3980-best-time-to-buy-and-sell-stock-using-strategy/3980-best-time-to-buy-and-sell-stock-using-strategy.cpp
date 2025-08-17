class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        vector<long long> prefOld(n+1, 0);
        vector<long long>prefPrice(n+1, 0);
        
        
        for (int i = 0; i < n; i++) {
            prefOld[i+1] = prefOld[i] + 1LL * strategy[i] * prices[i];
            prefPrice[i+1] = prefPrice[i] + prices[i];
        }
        
       
        long long origProfit = prefOld[n];
        
        long long modify = 0;
        
        for (int l = 0; l + k <= n; l++) {
            int r = l + k - 1;
            int mid = l + k/2;
            
           
            long long oldContrib = prefOld[r+1] - prefOld[l];
            
            
            long long change = prefPrice[r+1] - prefPrice[mid];
            
            long long gain = change - oldContrib;
            modify = max(modify, gain);
        }
        
        return origProfit + modify;
    }
};