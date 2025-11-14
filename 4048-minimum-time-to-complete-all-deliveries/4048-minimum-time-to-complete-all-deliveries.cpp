class Solution {
public:
    long long minimumTime(vector<int>& d, vector<int>& r) {
        long long d1 = d[0], d2 = d[1];
        long long r1 = r[0], r2 = r[1];
        long long L = lcm(r1, r2);

        auto can = [&](long long T) {
            long long c1 = T - T / r1;
            long long c2 = T - T / r2;

            long long shared = T - T / r1 - T / r2 + T / L;

            // exclusive hours
            long long ex1 = c1 - shared;
            long long ex2 = c2 - shared;

            // remaining deliveries after using exclusive hours
            long long rem1 = max(0LL, d1 - ex1);
            long long rem2 = max(0LL, d2 - ex2);

            long long need = rem1 + rem2;

            return need <= shared;
        };

        long long low = 1, high = 4e18, ans = -1;

        while (low <= high) {
            long long mid = (low + high) / 2;
            if (can(mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};