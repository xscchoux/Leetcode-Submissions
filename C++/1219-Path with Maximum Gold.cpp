class Solution {
public:
    int row, col;
    bool visited[15][15] {};
    int cal(int r, int c, vector<vector<int>>& grid) {
        if (r == row || c == col || r < 0 || c < 0 || grid[r][c] == 0 || visited[r][c]) return 0;
        int res = grid[r][c];
        visited[r][c] = true;
        res += max(max(cal(r+1, c, grid), cal(r, c+1, grid)), max(cal(r-1, c, grid), cal(r, c-1, grid)));
        visited[r][c] = false;
        return res;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        this->row = grid.size();
        this->col = grid[0].size();
        int res = 0;
        for (int r=0; r<row; r++) {
            for (int c=0; c<col; c++) {
                if (grid[r][c] == 0) continue;
                res = max(res, cal(r, c, grid));
            }
        }
        return res;
    }
};