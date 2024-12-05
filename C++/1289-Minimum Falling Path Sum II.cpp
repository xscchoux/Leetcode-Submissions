class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        // simple O(n^3) solution
        // int row = grid.size(), col = grid[0].size();
        // vector<vector<int>> dp(row, vector<int>(col, INT_MAX/2));
        // for (int r=0; r<row; r++) {
        //     for (int c=0; c<col; c++) {
        //         if (r == 0) {
        //             dp[r][c] = grid[r][c];
        //         } else {
        //             for (int cc = 0; cc < col; cc++) {
        //                 if (cc == c) continue;
        //                 dp[r][c] = min(dp[r-1][cc] + grid[r][c], dp[r][c]);
        //             }
        //         }
        //     }
        // }

        // return *min_element(dp[row-1].begin(), dp[row-1].end());

        // O(n^2)
        int row = grid.size(), col = grid[0].size();
        int minInd1 = -1, minInd2 = -1, minVal1 = INT_MAX/2, minVal2 = INT_MAX/2;
`
        for (int c=0; c<col; c++) {
            if (grid[0][c] < minVal1) {
                minVal2 = minVal1;
                minInd2 = minInd1;
                minVal1 = grid[0][c];
                minInd1 = c;
            } else if (grid[0][c] < minVal2) {
                minVal2 = grid[0][c];
                minInd2 = c;
            }
        }

        for (int r=1; r<row; r++) {
            int nxtInd1 = -1, nxtInd2 = -1, nxtVal1 = INT_MAX/2, nxtVal2 = INT_MAX/2;
            for (int c=0; c<col; c++) {
                int value;
                if (c != minInd1) {
                    value = minVal1 + grid[r][c];
                } else {
                    value = minVal2 + grid[r][c];
                }

                if (value < nxtVal1) {
                    nxtVal2 = nxtVal1;
                    nxtInd2 = nxtInd1;
                    nxtVal1 = value;
                    nxtInd1 = c;
                } else if (value < nxtVal2) {
                    nxtVal2 = value;
                    nxtInd2 = c;
                }
            }
            minInd1 = nxtInd1;
            minInd2 = nxtInd2;
            minVal1 = nxtVal1;
            minVal2 = nxtVal2;
        }

        return minVal1;
    }
};