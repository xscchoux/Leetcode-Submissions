using LL = long long;
class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int row = points.size(), col = points[0].size();
        vector<vector<LL>> dp(row, vector<LL>(col, 0));

        for (int c=0;c<col;c++) dp[0][c] = points[0][c];

        for (int r=1;r<row;r++) {
            LL leftMax = -1;
            for (int c=0;c<col;c++) {
                leftMax = max(leftMax-1, dp[r-1][c]);
                dp[r][c] = points[r][c] + leftMax;
            }

            LL rightMax = -1;
            for (int c=col-1;c>=0;c--) {
                rightMax = max(rightMax-1, dp[r-1][c]);
                dp[r][c] = max(dp[r][c], points[r][c] + rightMax);
            }
        }

        LL res = 0;
        for (int c=0; c<col; c++) {
            res = max(res, dp[row-1][c]);
        }

        return res;
    }
};


// space optimized
using LL = long long;
class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int row = points.size(), col = points[0].size();
        vector<LL> currRow(col, 0), prevRow(col, 0);

        for (int c=0;c<col;c++) prevRow[c] = points[0][c];

        for (int r=1;r<row;r++) {
            LL leftMax = -1;
            for (int c=0;c<col;c++) {
                leftMax = max(leftMax-1, prevRow[c]);
                currRow[c] = points[r][c] + leftMax;
            }

            LL rightMax = -1;
            for (int c=col-1;c>=0;c--) {
                rightMax = max(rightMax-1, prevRow[c]);
                currRow[c] = max(currRow[c], points[r][c] + rightMax);
            }
            prevRow = currRow;
        }

        LL res = 0;
        for (int c=0; c<col; c++) {
            res = max(res, prevRow[c]);
        }

        return res;
    }
};