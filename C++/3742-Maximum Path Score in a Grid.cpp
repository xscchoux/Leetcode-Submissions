class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int row = grid.size(), col = grid[0].size();
        int kMax = min(row+col-1, k);

        // dp[rowIdx][colIdx][cost]:score
        vector<vector<vector<int>>> dp(row, vector<vector<int>>(col, vector<int>(kMax+1, -1)));
        dp[0][0][(bool)grid[0][0]] = grid[0][0];   // smart trick

        for (int r=0; r<row; r++) {
            for (int c=0; c<col; c++) {
                for (int kk=0; kk<=kMax; kk++) {
                    if (r-1 >= 0 && dp[r-1][c][kk] != -1 && kk + (bool)grid[r][c] <= k) {
                        dp[r][c][kk + (bool)grid[r][c]] = max(dp[r][c][kk + (bool)grid[r][c]], grid[r][c] + dp[r-1][c][kk]);
                    }
                    if (c-1 >= 0 && dp[r][c-1][kk] != -1 && kk + (bool)grid[r][c] <= k) {
                        dp[r][c][kk + (bool)grid[r][c]] = max(dp[r][c][kk + (bool)grid[r][c]], grid[r][c] + dp[r][c-1][kk]);
                    }
                }
            }
        }

        int res = -1;

        for (int val:dp[row-1][col-1]) {
            res = max(res, val);
        }

        return res;
    }
};