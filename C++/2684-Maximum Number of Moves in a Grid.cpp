class Solution {
public:
    vector<vector<int>> memo;
    int row, col;
    int cal(int r, int c, vector<vector<int>>& grid) {
        // (row - 1, col + 1)
        if (memo[r][c] != -1) return memo[r][c];
        int mx = 0;
        if (r-1>=0 && c+1 <col && grid[r-1][c+1] > grid[r][c]) {
            mx = max(mx, 1+cal(r-1, c+1, grid));
        }
        // (row, col + 1)
        if (c+1 < col && grid[r][c+1] > grid[r][c]) {
            mx = max(mx, 1+cal(r, c+1, grid));
        }
        // (row + 1, col + 1)
        if (r+1<row && c+1 < col && grid[r+1][c+1] > grid[r][c]) {
            mx = max(mx, 1+cal(r+1, c+1, grid));
        }
        return memo[r][c] = mx;
    }
    int maxMoves(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();
        memo.resize(row, vector<int>(col, -1));
        int res = 0;
        for (int r=0; r<row; r++) {
            res = max(res, cal(r, 0, grid));
        }
        return res;
    }
};