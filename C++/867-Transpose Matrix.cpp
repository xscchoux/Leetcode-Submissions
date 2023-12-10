class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        vector<vector<int>> res(col, vector(row, 0));
        
        for (int r=0; r<row; r++){
            for (int c=0; c<col; c++){
                res[c][r] = matrix[r][c];
            }
        }
        
        return res;
    }
};