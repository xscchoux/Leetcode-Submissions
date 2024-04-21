class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        vector<vector<int>> cnt(col, vector<int>(10, 0));
        vector<vector<int>> dp(col, vector<int>(10, 0));
        
        for (int c=0; c<col; c++) {
            for (int r=0; r<row; r++) {
                cnt[c][grid[r][c]] += 1;
            }
        }
        
        for (int curVal=0; curVal<10; curVal++) {
            dp[0][curVal] = cnt[0][curVal];
        }
        
        for (int c=1; c<col; c++) {
            for (int preVal=0; preVal<10; preVal++) {
                for (int curVal=0; curVal<10; curVal++) {
                    if (curVal == preVal) continue;
                    dp[c][curVal] = max(dp[c][curVal], dp[c-1][preVal] + cnt[c][curVal]);
                }
            }
        }
        
        return row*col - *max_element(dp[col-1].begin(), dp[col-1].end());
    }
};