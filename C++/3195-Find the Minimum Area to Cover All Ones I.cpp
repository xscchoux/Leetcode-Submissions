class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        int up = row-1, down = 0, left = col-1, right = 0;

        for (int r = 0; r<row; r++) {
            for (int c = 0; c<col; c++) {
                if (grid[r][c] == 1) {
                    up = min(r, up);
                    down = max(r, down);
                    left = min(c, left);
                    right = max(c, right);
                }
            }
        }

        return (right-left+1)*(down-up+1);
    }
};