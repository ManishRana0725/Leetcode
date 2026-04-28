class Solution {
public:
    // greedy problems all ways sucks 
    int minGroupsForValidAssignment(vector<int>& balls) {
        unordered_map<int,int> freq;
        for (int x : balls) freq[x]++;
        
        int ans = INT_MAX;
        
        int minFreq = INT_MAX;
        for (auto& [_, f] : freq) {
            minFreq = min(minFreq, f);
        }
        
        for (int k = 1; k <= minFreq; k++) {
            int total = 0;
            bool ok = true;
            
            for (auto& [_, f] : freq) {
                int groups = (f + k) / (k + 1); 
                
                if (groups * k > f) {
                    ok = false;
                    break;
                }
                
                total += groups;
            }
            
            if (ok) ans = min(ans, total);
        }
        
        return ans;
    }
};