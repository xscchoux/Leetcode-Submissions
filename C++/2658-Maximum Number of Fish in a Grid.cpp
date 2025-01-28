class Solution {
public:
    int row, col;
    int d[5] = {1, 0, -1, 0, 1};
    int count(vector<vector<int>>& grid, int r, int c) {
        int res = grid[r][c];
        grid[r][c] = 0;
        for (int i=0; i<4; i++) {
            int nr = r+d[i], nc = c+d[i+1];
            if (0<=nr && nr<row && 0<=nc && nc<col && grid[nr][nc] > 0) {
                res += count(grid, nr, nc);
            }
        }
        return res;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();
        int res = 0;
        for (int r=0; r<row; r++) {
            for (int c=0; c<col; c++) {
                if (grid[r][c] > 0) {
                    res = max(res, count(grid, r, c));
                }
            }
        }
        return res;
    }
};