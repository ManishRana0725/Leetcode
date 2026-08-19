class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int m = reservedSeats.size();

        unordered_map<int , vector<int>> mpp;

        sort(reservedSeats.begin() , reservedSeats.end());

        for(auto it : reservedSeats){
            mpp[it[0]].push_back(it[1]);
        }

        int ans = 0;

        int remaining = n - mpp.size();

        ans += remaining*2;

        for(auto it : mpp){

            vector<int> v = it.second;
            vector<bool> empty(11 , true);
            for(int i=0 ; i<v.size() ; i++){
                empty[v[i]] = false;
            }
            bool flag1 = true;
            if(empty[2] && empty[3] && empty[4] && empty[5]){
                ans+=1;
                flag1 = false;
            }
            bool flag2 = true;
            if(empty[4] && empty[5] && empty[6] && empty[7] && flag1){
                ans+=1;
                flag2 = false;
                
            }
            if(empty[6] && empty[7] && empty[8] && empty[9] && flag2){
                ans+=1;
            }

        }
        return ans;
        
    }
};