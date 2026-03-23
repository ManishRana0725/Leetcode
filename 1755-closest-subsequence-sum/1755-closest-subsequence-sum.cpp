class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        int mid = n/2;

        vector<int> left(nums.begin() , nums.begin()+mid);
        vector<int> right(nums.begin()+mid , nums.end());


        vector<int> leftmpp , rightmpp;
        int n1 = left.size();
        for(int mask = 0 ; mask < (1 << n1) ; mask++){

            int sum = 0;
            for(int i=0 ; i<n1 ; i++){
                if(mask & (1 << i)){
                    sum += left[i];
                }
            }
            leftmpp.push_back(sum);
        }

        int n2 = right.size();
        for(int mask = 0 ; mask < (1 << n2) ; mask++){
            int sum = 0 ;
            for(int i=0 ; i<n2 ; i++){
                if(mask & (1 << i)){
                    sum += right[i];
                }
            }
            rightmpp.push_back(sum);
        }

        sort(leftmpp.begin() , leftmpp.end());
        sort(rightmpp.begin() , rightmpp.end());

        int ans = INT_MAX;

        for(int i=0 ; i<leftmpp.size() ; i++){
            int need = goal - leftmpp[i];

            auto it = lower_bound(rightmpp.begin() , rightmpp.end() , need);

            
            if(it != rightmpp.end()){
                int value = *it;
                ans = min(ans , abs((leftmpp[i]+value) - goal));
            }

            if(it != rightmpp.begin()){
                it--;
                int value = *it;
                ans = min(ans , abs((leftmpp[i]+value) - goal));
            }
        }

        return ans;
    }
};