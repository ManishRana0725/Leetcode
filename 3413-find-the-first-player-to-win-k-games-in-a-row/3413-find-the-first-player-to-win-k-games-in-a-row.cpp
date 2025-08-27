class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int n = skills.size();
        priority_queue<pair<int , int>> pq;

        if(n <= k){
            int maxi = 0;
            int ind = 0;
            for(int i=0 ; i < n; i++){
                if(maxi < skills[i]){
                    ind = i;
                }
                maxi = max(maxi ,skills[i]);
            }
            return ind;
        }
        for(int i=0 ;i<n;i++){
            pq.push({skills[i] , i});
            if(pq.size() > k){
                auto [j , ind] = pq.top();
                if(i - ind +1  >= k){
                    return ind;
                    
                }
            }
            
        }
        return pq.top().second;
    }
};