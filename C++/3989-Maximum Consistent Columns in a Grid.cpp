class Solution {
public:
    int maxConsistentColumns(vector<vector<int>>& grid, int limit) {
        int row = grid.size(), col = grid[0].size();
        vector<vector<bool>> compatible(col, vector<bool>(col, false));

        for (int c1=0; c1<col; c1++) {
            for (int c2=0; c2<c1; c2++) {
                bool found = true;
                for (int r=0; r<row; r++) {
                    if (abs(grid[r][c1] - grid[r][c2]) > limit) {
                        found = false;
                        break;
                    }
                }
                if (found) {
                    compatible[c1][c2] = true;
                }
            }
        }

        // Only need to check adjacent columns
        vector<int> dp(col, 1);
        for (int c1=0; c1<col; c1++) {
            for (int c2=0; c2<c1; c2++) {
                if (compatible[c1][c2]) {
                    dp[c1] = max(dp[c1], dp[c2]+1);
                }
            }
        }

        return *max_element(begin(dp), end(dp));
    }
};