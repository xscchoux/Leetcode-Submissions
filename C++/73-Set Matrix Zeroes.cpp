class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        bool rowZero = false, colZero = false;
        for (int r=0; r<row; r++) {
            for (int c=0; c<col; c++) {
                if (matrix[r][c] == 0) {
                    if (c == 0) colZero = true;
                    if (r == 0) rowZero = true;
                    matrix[r][0] = 0;
                    matrix[0][c] = 0;
                }
            }
        }

        for (int r=1; r<row; r++) {
            for (int c=1; c<col; c++) {
                if (matrix[r][0] == 0 || matrix[0][c] == 0) {
                    matrix[r][c] = 0;
                }
            }
        }

        if (rowZero) {
            for (int c=0; c<col; c++) {
                matrix[0][c] = 0;
            }
        }

        if (colZero) {
            for (int r=0; r<row; r++) {
                matrix[r][0] = 0;
            }
        }

    }
};