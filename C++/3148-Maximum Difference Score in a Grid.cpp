class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        int res = INT_MIN/2;
        for (int r=row-1; r>=0; r--) {
            for (int c=col-1, tmp=INT_MIN/2; c>=0; c--) {
                int curr = grid[r][c];
                if (r+1 < row) {
                    tmp = max(tmp, grid[r+1][c]);
                }
                if (c+1 < col) {
                    tmp = max(tmp, grid[r][c+1]);
                }
                res = max(res, tmp-curr);
                grid[r][c] = max(grid[r][c], tmp);
            }
        }
        return res;
    }
};