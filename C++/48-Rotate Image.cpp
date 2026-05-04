class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();

        for (int r=1; r<row; r++) {
            for (int c=0; c<r; c++) {
                swap(matrix[r][c], matrix[c][r]);
            }
        }

        for (auto &r:matrix) {
            reverse(r.begin(), r.end());
        }

    }
};