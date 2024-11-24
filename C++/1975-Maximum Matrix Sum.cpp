using LL = long long;
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        LL tot = 0;
        int row = matrix.size(), col = matrix[0].size(), minusCnt = 0, mn = INT_MAX;
        for (int r=0; r<row; r++) {
            for (int c=0; c<col; c++) {
                tot += abs(matrix[r][c]);
                mn = min(mn, abs(matrix[r][c]));
                if (matrix[r][c] <= 0) {
                    minusCnt++;
                }
            }
        }

        if (minusCnt%2 == 0) {
            return tot;
        } else {
            return tot - 2*mn;
        }

    }
};