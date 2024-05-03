class Solution {
private:
    vector<pair<int, int>> directions;
    int row, col;
public:
    void dfs(int r, int c, vector<vector<char>>& grid) {
        grid[r][c] = '0';
        for (auto [dr, dc]:directions) {
            int nr = r+dr, nc = c+dc;
            if (nr<0 || nr >= row || nc<0 || nc>=col) continue;
            if (grid[nr][nc] == '1') {
                dfs(nr, nc, grid);
            }
        }
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        row = grid.size();
        col = grid[0].size();
        int res = 0;
        directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        
        for (int r=0; r<row; r++) {
            for (int c=0; c<col; c++) {
                if (grid[r][c] == '1') {
                    dfs(r, c, grid);
                    res += 1;
                }
            }
        }
        return res;
    }
};