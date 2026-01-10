class Solution {
public:
    int kMod = 1e9+7;
    int numberOfRoutes(vector<string>& grid, int d) {
        int row = grid.size(), col = grid[0].size();
        vector<vector<long long>> dp(row, vector<long long>(col, 0));

        bool found1 = false, found2 = false;
        for (int c=0; c<col; c++) {
            if (grid[row-1][c] == '.') {
                dp[row-1][c] = 1;
                found1 = true;
            }
            if (grid[0][c] == '.') {
                found2 = true;
            }
        }

        if (!found1 && !found2) return 0;

        for (int r=row-1; r>=0; r--) {
            vector<long long> prev = dp[r];
            vector<long long> preSum(col+1, 0);

            for (int c=0; c<col; c++) {
                preSum[c+1] = (preSum[c] + ((grid[r][c] == '#')?0:prev[c]))%kMod;
            }

            // update current row
            for (int c=0; c<col; c++) {
                if (grid[r][c] == '#') continue;
                int leftMost = max(0, c-d);
                int rightMost = min(col-1, c+d);
                dp[r][c] = (dp[r][c] + preSum[c] - preSum[leftMost] + kMod)%kMod;
                dp[r][c] = (dp[r][c] + preSum[rightMost+1] - preSum[c+1] + kMod)%kMod;
            }
            // update upper row using difference array
            if (r > 0) {
                int nxtR = r-1;
                for (int c=0; c<col; c++) {
                    if (grid[r][c] == '#') continue;
                    int leftMost = max(0, c - (int)sqrt(d*d-1));
                    int rightMost = min(col-1, c + (int)sqrt(d*d-1));
                    dp[nxtR][leftMost] = (dp[nxtR][leftMost] + dp[r][c])%kMod;
                    if (rightMost+1 < col) {
                        dp[nxtR][rightMost+1] = (dp[nxtR][rightMost+1] - dp[r][c])%kMod;
                    }
                }
                long long running = 0;
                for (int c=0; c<col; c++) {
                    running = (running + dp[nxtR][c])%kMod;
                    dp[nxtR][c] = running;
                }                
            }
        }

        long long res = 0;
        for (int c=0; c<col; c++) {
            if (grid[0][c] =='#') continue;
            res = (res + dp[0][c])%kMod;
        }

        return res;
    }
};