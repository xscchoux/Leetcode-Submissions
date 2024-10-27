// First AC
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        vector<vector<int>> dp(row+1, vector<int>(col+1, 0));
        
        for (int r=1; r<=row; r++) {
            for (int c=1; c<=col; c++) {
                dp[r][c] = matrix[r-1][c-1] + dp[r][c-1] + dp[r-1][c] - dp[r-1][c-1];
            }
        }

        int res = 0;
        for (int r=0; r<row; r++) {
            for (int c=0; c<col; c++) {
                if (matrix[r][c] == 0) continue;
                int length = 1;
                while (r-length+1>=0 && c-length+1>=0) {
                    int tot = dp[r+1][c+1] - dp[r+1][c+1-length] - dp[r+1-length][c+1] + dp[r+1-length][c+1-length];
                    if (tot != length*length) break;
                    res++;
                    length++;
                }
            }
        }
        return res;
    }
};

// Much better
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        int res = 0;
        for (int r=1; r<row; r++) {
            for (int c=1; c<col; c++) {
                if (matrix[r][c] == 0) continue;
                matrix[r][c] = 1 + min({matrix[r-1][c], matrix[r][c-1], matrix[r-1][c-1]});
            }
        }

        for (int r=0; r<row; r++) {
            for (int c=0; c<col; c++) {
                res += matrix[r][c];
            }
        }


        return res;
    }
};
