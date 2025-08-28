class Solution {
public:
    int countDays(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin() , meetings.end());

        vector<pair<int,int>> v;

        for(auto it : meetings){
            
            if(v.empty() || v.back().second < it[0] ){
                v.push_back({it[0] , it[1]});
            }else{
                v.back().second = max(v.back().second , it[1]);
            }
        }

        int count = 0;
        for(auto it : v){
            int diff = it.second - it.first;
            count += (diff+1);
        }

        return n-count;
    }
};