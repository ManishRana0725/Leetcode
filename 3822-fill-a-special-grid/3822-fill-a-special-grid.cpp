class Solution {
public:
    vector<vector<int>> ans;
    void solve(int r1, int r2, int c1, int c2, int start, int end) {
        int size = r2 - r1 + 1;

        // Base case: 1x1 grid
        if (size == 1) {
            ans[r1][c1] = start;
            return;
        }

        int q = (end - start + 1) / 4;

        // Value ranges for each quadrant
        int startTR = start;           // top-right
        int endTR = start + q - 1;
        int startBR = endTR + 1;       // bottom-right
        int endBR = startBR + q - 1;
        int startBL = endBR + 1;       // bottom-left
        int endBL = startBL + q - 1;
        int startTL = endBL + 1;       // top-left
        int endTL = end;

        int midRow = (r1 + r2) / 2;
        int midCol = (c1 + c2) / 2;

        // Recursively fill quadrants
        solve(r1, midRow, midCol + 1, c2, startTR, endTR);   // top-right
        solve(midRow + 1, r2, midCol + 1, c2, startBR, endBR); // bottom-right
        solve(midRow + 1, r2, c1, midCol, startBL, endBL);   // bottom-left
        solve(r1, midRow, c1, midCol, startTL, endTL);       // top-left
        return;
    }

    vector<vector<int>> specialGrid(int n) {
        int m = 1 << n;
        ans.assign(m, vector<int>(m, 0));
        solve(0, m - 1, 0, m - 1, 0, m * m - 1);
        return ans;
    }
};