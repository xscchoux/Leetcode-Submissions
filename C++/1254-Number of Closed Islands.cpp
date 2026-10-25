class Solution {
public:
    int row, col;
    int d[5] = {0, 1, 0, -1, 0};
    void dfs(int r, int c, vector<vector<int>>& grid) {
        grid[r][c] = 1;
        for (int i=0; i<4; i++) {
            int nr = r+d[i], nc = c+d[i+1];
            if (nr>=0 && nr<row && nc>=0 && nc<col && grid[nr][nc] == 0) {
                dfs(nr, nc, grid);
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        this->row = grid.size();
        this->col = grid[0].size();

        if (row <= 2 || col <= 2) return 0;

        // check all 4 sides
        for (int r=0; r<row; r++) {
            if (grid[r][0] == 0) {
                dfs(r, 0, grid);
            }
        }

        for (int c=0; c<col; c++) {
            if (grid[0][c] == 0) {
                dfs(0, c, grid);
            }
        }

        for (int r=0; r<row; r++) {
            if (grid[r][col-1] == 0) {
                dfs(r, col-1, grid);
            }
        }

        for (int c=0; c<col; c++) {
            if (grid[row-1][c] == 0) {
                dfs(row-1, c, grid);
            }
        }

        int res = 0;
        for (int r=1; r<row-1; r++) {
            for (int c=1; c<col-1; c++) {
                if (grid[r][c] == 0) {
                    dfs(r, c, grid);
                    res++;
                }
            }
        }

        return res;
    }
};