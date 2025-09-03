class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();

        unordered_map<int,int> ball , col;
        vector<int>ans;
        int count = 0;
        for(int i=0 ;i<n ;i++){
            int pos = queries[i][0] ;
            int c = queries[i][1];

            if(ball.find(pos) != ball.end()){
                if(--col[ball[pos]] == 0 ){
                    count--;
                }
                ball[pos] = c;
                col[c]++;
                if(col[c] == 1)count++;
            }else{
                col[c]++;
                ball[pos] = c;
                if(col[c] == 1)count++;
            }

            ans.push_back(count);
        }
        return ans;
    }
};