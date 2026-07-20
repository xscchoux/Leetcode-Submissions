class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int row = grid.size(), col = grid[0].size(), tot = row*col;
        vector<vector<int>> res(row, vector<int>(col, 0));

        for (int r=0; r<row; r++) {
            for (int c=0; c<col; c++) {
                int num = (r*col + c + k)%tot;
                int nr = num/col, nc = num%col;
                res[nr][nc] = grid[r][c]; 
            }
        }

        return res;
    }
};