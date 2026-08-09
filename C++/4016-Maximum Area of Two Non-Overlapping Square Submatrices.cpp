class Solution {
public:
    int row, col;
    int isOK(vector<vector<int>>& dp, int k) {
        int minRow = row, maxRow = 0, minCol = col, maxCol = 0;
        for (int r=k; r<=row; r++) {
            for (int c=k; c<=col; c++) {
                int oneCnt = dp[r][c] - dp[r-k][c] - dp[r][c-k] + dp[r-k][c-k];
                if (oneCnt == k*k) {
                    minRow = min(minRow, r);
                    maxRow = max(maxRow, r);

                    minCol = min(minCol, c);
                    maxCol = max(maxCol, c);
                }
            }
        }

        // vertically split ?
        if (maxRow - k >= minRow) {
            return true;
        }

        // horizontally split ?
        if (maxCol - k >= minCol) {
            return true;
        }
        
        return false;
    }
    int maxArea(vector<vector<int>>& mat) {
        this->row = mat.size();
        this->col = mat[0].size();
        int side = max(row, col);

        vector<vector<int>> dp(row+1, vector<int>(col+1, 0));

        // preprocessing
        for (int r=0; r<row; r++) {
            for (int c=0; c<col; c++) {
                dp[r+1][c+1] = dp[r][c+1] + dp[r+1][c] - dp[r][c] + (mat[r][c] == 1);
            }
        }

        int left = 1, right = side/2;
        while (left + 1 < right) {
            int mid = left + (right-left)/2;
            if (isOK(dp, mid)) {
                left = mid;
            } else {
                right = mid;
            }
        } 

        if (isOK(dp, right)) {
            return right*right;
        } else if (isOK(dp, left)) {
            return left*left;
        } else {
            return 0;
        }
    }
};