class Solution {
public:
    vector<vector<int>> adj;
    vector<long long> coins;
    vector<int> cost;

    struct Info {
        long long mx[3];   
        long long mn[2];   
        int mxsz = 0;
        int mnsz = 0;
        int sz = 0;
    };

    void addMin(Info &a, long long val) {
        if (a.mnsz < 2) {
            a.mn[a.mnsz++] = val;
            sort(a.mn, a.mn + a.mnsz);
        } else if (val < a.mn[1]) {
            a.mn[1] = val;
            if (a.mn[1] < a.mn[0]) swap(a.mn[0], a.mn[1]);
        }
    }

    void addMax(Info &a, long long val) {
        if (a.mxsz < 3) {
            a.mx[a.mxsz++] = val;
            sort(a.mx, a.mx + a.mxsz, greater<long long>());
        } else if (val > a.mx[2]) {
            a.mx[2] = val;
            sort(a.mx, a.mx + 3, greater<long long>());
        }
    }


    Info dfs(int u, int parent) {
        Info cur;
        cur.sz = 1;

        addMax(cur, cost[u]);
        addMin(cur, cost[u]);

        for (int v : adj[u]) {
            if (v == parent) continue;

            Info child = dfs(v, u);
            cur.sz += child.sz;

            for (int i = 0; i < child.mxsz; i++)
                addMax(cur, child.mx[i]);

            for (int i = 0; i < child.mnsz; i++)
                addMin(cur, child.mn[i]);
        }

        if (cur.sz < 3) {
            coins[u] = 1;
        } else {
            long long best = LLONG_MIN;


            if (cur.mxsz >= 3)
                best = max(best, cur.mx[0] * cur.mx[1] * cur.mx[2]);

            if (cur.mnsz >= 2 && cur.mxsz >= 1)
                best = max(best, cur.mn[0] * cur.mn[1] * cur.mx[0]);

            coins[u] = max(0LL, best);
        }

        return cur;
    }

    vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& cost_) {
        int n = cost_.size();
        cost = cost_;
        adj.assign(n, {});
        coins.assign(n, 0);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(0, -1);
        return coins;
    }
};
