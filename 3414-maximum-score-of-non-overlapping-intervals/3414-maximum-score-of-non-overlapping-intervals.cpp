class Solution {
public:
    struct Node {
        long long cost = -1 ;
        vector<int> indtaken;
    };

    vector<int> nextInd;
    vector<vector<Node>> dp;
    

    int findind(int value, vector<vector<int>>& intervals, int ind) {

        int n = intervals.size();

        int s = ind + 1;
        int e = n - 1;
        int ans = n;

        while (s <= e) {

            int mid = s + (e - s) / 2;

            if (intervals[mid][0] > value) {
                ans = mid;
                e = mid - 1;
            }
            else {
                s = mid + 1;
            }
        }

        return ans;
    }

    Node solve( int i , int k , vector<vector<int>>& intervals ) {

        int n = intervals.size();

        if (k == 0 || i >= n)
            return Node();

        if(dp[i][k].cost != -1)return dp[i][k];

        Node nottake = solve(i + 1, k, intervals);

        Node temp = solve(nextInd[i], k - 1, intervals);

        Node take;
        take.cost = temp.cost+intervals[i][2];
        take.indtaken = temp.indtaken;
        take.indtaken.push_back(intervals[i][3]);
        
        sort(begin(take.indtaken) , end(take.indtaken));

        Node result ;
        if(nottake.cost > take.cost){
            result = nottake;
        }else if(take.cost > nottake.cost){
            result = take;
        }else{
            result = (nottake.indtaken < take.indtaken ) ? nottake : take;
        }
        

        return dp[i][k] = result;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        int n = intervals.size();

        dp.assign(n+1 , vector<Node> (4+1));
        for (int i = 0; i < n; i++) {
            intervals[i].push_back(i);
        }

        sort(intervals.begin(), intervals.end());

        nextInd.resize(n);

        for (int i = 0; i < n; i++) {
            nextInd[i] = findind(intervals[i][1], intervals, i);
        }

        Node ans = solve(0, 4, intervals);

        sort(ans.indtaken.begin(), ans.indtaken.end());

        return ans.indtaken;
    }
};