class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        // O(row + col)
        int row = rowSum.size(), col = colSum.size();
        vector<vector<int>> matrix(row, vector<int>(col, 0));

        int r = 0, c = 0;
        while (r<row && c<col) {
            matrix[r][c] = min(rowSum[r], colSum[c]);
            rowSum[r] -= matrix[r][c];
            colSum[c] -= matrix[r][c];
            rowSum[r] == 0? r++:c++;
        }

        return matrix;
    }
};