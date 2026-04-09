class Solution {
public:
    vector<int> parent, size, parity;

    pair<int,int> find(int x) {
        if (parent[x] == x)
            return {x, 0};

        auto [root, par] = find(parent[x]);
        parent[x] = root;
        parity[x] ^= par;

        return {parent[x], parity[x]};
    }

    bool unite(int u, int v, int w) {
        auto [pu, xu] = find(u);
        auto [pv, xv] = find(v);

        if (pu == pv) {
            return ((xu ^ xv) == w);
        }

        if (size[pu] < size[pv]) {
            swap(pu, pv);
            swap(xu, xv);
        }

        parent[pv] = pu;

        parity[pv] = xu ^ xv ^ w;

        size[pu] += size[pv];

        return true;
    }

    int numberOfEdgesAdded(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        size.resize(n, 1);
        parity.resize(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        int count = 0;

        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];

            if (unite(u, v, w))
                count++;
        }

        return count;
    }
};