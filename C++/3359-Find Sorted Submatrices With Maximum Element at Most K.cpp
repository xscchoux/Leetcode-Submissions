// https://leetcode.com/problems/find-sorted-submatrices-with-maximum-element-at-most-k/solutions/6066625/python3-count-submatrices-with-all-ones/
using LL = long long;
class Solution {
public:
    int row, col;
    LL res;
    void cal(vector<vector<int>>& dp, vector<vector<int>>& grid) {
        for (int c=0; c<col; c++) {
            stack<int> stk;  //  make monotonically increasing stack (histogram) on each row. 
            LL count = 0;
            for (int r=0; r<row; r++) {
                while (!stk.empty() && dp[stk.top()][c] >= dp[r][c]) {
                    int right = stk.top();
                    stk.pop();
                    int left = (!stk.empty()?stk.top():-1);
                    count -= (dp[right][c]-dp[r][c])*(right-left);  // // minus unused histograms from left+1 ~ right
                }
                stk.push(r);
                count += dp[r][c];
                res += count;
            }
        }

    }
    long long countSubmatrices(vector<vector<int>>& grid, int k) {
        this->row = grid.size();
        this->col = grid[0].size();
        res = 0;
        vector<vector<int>> dp(row, vector<int>(col, 0)); // the length decreasing subarray that ends with dp[r][c] at current row

        for (int r=0; r<row; r++) {
            for (int c=0; c<col; c++) {
                if (grid[r][c] > k) continue;
                if (c > 0 && grid[r][c] <= grid[r][c-1]) {
                    dp[r][c] = dp[r][c-1] + 1;
                } else {
                    dp[r][c] = 1;
                }
            }
        }

        cal(dp, grid);

        return res;
    }
};