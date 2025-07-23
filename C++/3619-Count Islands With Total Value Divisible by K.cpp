class Solution {
public:
    int row, col;
    long long dfs(int r, int c, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        if ( r<0 || r>=row || c<0 || c>=col || visited[r][c] || grid[r][c] == 0) {
            return 0;
        }
        long long res = grid[r][c];
        visited[r][c] = true;

        res += dfs(r+1, c, grid, visited);
        res += dfs(r, c+1, grid, visited);
        res += dfs(r-1, c, grid, visited);
        res += dfs(r, c-1, grid, visited);

        return res;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        this->row = grid.size();
        this->col = grid[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        int res = 0;

        for (int r=0; r<row; r++) {
            for (int c=0; c<col; c++) {
                if (grid[r][c] == 0 || visited[r][c]) continue;
                int tot = dfs(r, c, grid, visited);
                if (tot%k == 0) res++;
            }
        }

        return res;
    }
};