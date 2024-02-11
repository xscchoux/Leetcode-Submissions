class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        // dp[row_number][robot1 column][robot2 column]
        // cannot use dp[grid.size()][grid[0].size()][grid[0].size()] because
        // size of built-in arrays need to be compile-time constants
        int row = grid.size(), col = grid[0].size();
        int dp[70][70][70];
        memset(dp, -1, sizeof(dp));
        dp[0][0][col-1] = grid[0][0] + grid[0][col-1];
        int res = 0;
        
        for (int r=1; r<row; r++){
            for (int c2=0; c2<col; c2++) {
                for (int c1 = 0; c1<=c2; c1++) {
                    for (int preC1=c1-1; preC1<=c1+1; preC1++) {
                        if (preC1<0 || preC1 >= col) continue;
                        for (int preC2=c2-1; preC2<=c2+1; preC2++) {
                            if (preC2 < 0 || preC2 >= col) continue;
                            if (dp[r-1][preC1][preC2] == -1) continue;
                            if (c1 == c2) {
                                dp[r][c1][c2] = max(dp[r][c1][c2], grid[r][c1] + dp[r-1][preC1][preC2]);
                            } else {
                                dp[r][c1][c2] = max(dp[r][c1][c2], grid[r][c1] + grid[r][c2] + dp[r-1][preC1][preC2]);
                            }                          
                        }
                    }
                }
            }
        }
        
        for (int c2=0; c2<col; c2++) {
            for (int c1=0; c1<c2; c1++){
                res = max(res, dp[row-1][c1][c2]);
            }
        }
        return res;
    }
};