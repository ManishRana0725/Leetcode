class Solution {
public:

    int m;
    vector<vector<int>> req;
    vector<vector<long long>> dp;

    long long solve(int mask, int last) {

        if (dp[mask][last] != -1) {
            return dp[mask][last];
        }

        if ((mask & (mask - 1)) == 0) {
            return dp[mask][last];
        }

        long long ans = LLONG_MAX;

        int prevMask = mask ^ (1 << last);

        for (int prev = 0; prev < m; prev++) {

            if (!(prevMask & (1 << prev))) {
                continue;
            }

            long long prevTime = solve(prevMask, prev);

            long long travel = abs( req[prev][1] - req[last][1]);
            long long reachTime = prevTime + travel;
            long long finishTime = max( reachTime , (long long)req[last][0]);

            ans = min(ans, finishTime);
        }

        return dp[mask][last] = ans;
    }


    long long elevatorRequests( int n , int start, vector<vector<int>>& requests)
    {

        req = requests;
        m = requests.size();

        dp.assign( 1 << m , vector<long long>(m, -1));

        for (int i = 0; i < m; i++) {

            long long travel = abs(start - req[i][1]);

            long long finishTime = max(travel , (long long)req[i][0]);

            dp[1 << i][i] = finishTime;
        }

        int fullMask = (1 << m) - 1;

        long long answer = LLONG_MAX;

        for (int last = 0; last < m; last++) {

            answer = min(answer , solve(fullMask, last) );
        }
        return answer;
    }
};