class Solution {
public:
    struct State {
    int i, j, health;
};

bool isSafe(int i, int j, int m, int n) {
    return i >= 0 && j >= 0 && i < m && j < n;
}
    
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();

    vector<vector<int>> maxHealth(m, vector<int>(n, -1)); // stores max health when visiting (i,j)
    queue<State> q;

    int startHealth = health - grid[0][0]; // lose 1 if starting cell is unsafe
    if (startHealth <= 0) return false;

    q.push({0, 0, startHealth});
    maxHealth[0][0] = startHealth;

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    while (!q.empty()) {
        auto [x, y, h] = q.front();
        q.pop();

        if (x == m - 1 && y == n - 1 && h >= 1) return true;

        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d], ny = y + dy[d];

            if (!isSafe(nx, ny, m, n)) continue;

            int nh = h - grid[nx][ny];
            if (nh <= 0) continue;

            if (nh > maxHealth[nx][ny]) {
                maxHealth[nx][ny] = nh;
                q.push({nx, ny, nh});
            }
        }
    }

    return false;
    }
};