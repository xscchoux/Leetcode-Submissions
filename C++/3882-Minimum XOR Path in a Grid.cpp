class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        vector<vector<vector<bool>>> dp(row, vector<vector<bool>>(col, vector<bool>(1024, false)));

        dp[0][0][grid[0][0]] = true;
        
        for (int r=0; r<row; r++) {
            for (int c=0; c<col; c++) {
                if (r == 0 && c == 0) continue;
                for (int val=0; val<=1023; val++) {
                    if (r-1>=0 && dp[r-1][c][val]) {
                        dp[r][c][grid[r][c]^val] = true;
                    }
                    if (c-1>=0 && dp[r][c-1][val]) {
                        dp[r][c][grid[r][c]^val] = true;
                    }
                }
            }
        }

        for (int val=0; val<=1023; val++) {
            if (dp[row-1][col-1][val]) {
                return val;
            }
        }

        return 0;
    }
};