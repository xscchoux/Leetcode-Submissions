class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int row = mat.size(), col = mat[0].size();
        vector<vector<int>> matrixSum(row, vector<int>(col, 0));

        for (int r=0; r<row; r++) {
            for (int c=0; c<col; c++) {
                if (r == 0 && c == 0) {
                    matrixSum[r][c] = mat[r][c];
                } else if (r == 0) {
                    matrixSum[r][c] = matrixSum[r][c-1] + mat[r][c];
                } else if (c == 0) {
                    matrixSum[r][c] = matrixSum[r-1][c] + mat[r][c];
                } else {
                    matrixSum[r][c] = matrixSum[r-1][c] + matrixSum[r][c-1] - matrixSum[r-1][c-1] + mat[r][c];
                }
            }
        }
        int res = 0;
        for (int side = 1; side <=  min(row, col); side++) {
            bool found = false;
            for (int r=side-1; r<row; r++) {
                for (int c=side-1; c<col; c++) {
                    int currSum = matrixSum[r][c];
                    if (r-side >= 0) {
                        currSum -= matrixSum[r-side][c];
                    }
                    if (c-side >= 0) {
                        currSum -= matrixSum[r][c-side];
                    }
                    if (c-side >= 0 && r-side >= 0) {
                        currSum += matrixSum[r-side][c-side];
                    }
                    if (currSum <= threshold) {
                        res = side;
                        found = true;
                        break;
                    }
                }
                if (found) {
                    break;
                }
            }
            if (!found) {
                break;
            }
        }


        return res;
    }
};