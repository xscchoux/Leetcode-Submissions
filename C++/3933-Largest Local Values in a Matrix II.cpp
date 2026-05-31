class Solution {
public:
    int check(vector<vector<vector<int>>>& preSum, int val, int r1, int r2, int c1, int c2) {
        return preSum[val][r2+1][c2+1] - preSum[val][r1][c2+1] - preSum[val][r2+1][c1] + preSum[val][r1][c1];
    }
    int countLocalMaximums(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();

        vector<vector<vector<int>>> preSum(201, vector<vector<int>>(row+1, vector<int>(col+1, 0)));
        
        // preSum[val][r][c]: count of cells in top-left submatrix with value > val

        for (int val=0; val<=200; val++) {
            for (int r=0; r<row; r++) {
                for (int c=0; c<col; c++) {
                    preSum[val][r+1][c+1] = preSum[val][r][c+1] + preSum[val][r+1][c] - preSum[val][r][c] + (matrix[r][c] > val);
                }
            }
        }
        int res = 0;
        for (int r=0; r<row; r++) {
            for (int c=0; c<col; c++) {
                if (matrix[r][c] == 0) continue;
                int r1 = max(0, r-matrix[r][c]), r2 = min(row-1, r+matrix[r][c]), c1 = max(0, c-matrix[r][c]), c2 = min(col-1, c+matrix[r][c]);
                int greaterCount = check(preSum, matrix[r][c], r1, r2, c1, c2);

                // remove contributions from corner points
                vector<array<int, 2>> corner = {{r-matrix[r][c], c-matrix[r][c]}, {r+matrix[r][c], c-matrix[r][c]}, {r-matrix[r][c], c+matrix[r][c]}, {r+matrix[r][c], c+matrix[r][c]}};

                for (auto [rVal, cVal]:corner) {
                    if (rVal < 0 || rVal >= row || cVal<0 || cVal >= col) continue;
                    if (matrix[rVal][cVal] > matrix[r][c]) {
                        greaterCount--;
                    }
                }
                if (greaterCount == 0) res++;
            }
        }

        return res;
    }
};