class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        vector<int> rowCount(row, 0), colCount(col, 0);
        
        for (int r = 0; r < row; r++){
            for (int c = 0; c < col; c++){
                if (grid[r][c] == 1){
                    rowCount[r]++;
                    colCount[c]++;
                }
            }
        }
        
        for (int r = 0; r < row; r++){
            for (int c = 0; c < col; c++){
                grid[r][c] = rowCount[r]*2 - row + colCount[c]*2 - col;
            }
        }
        
        return grid;
    }
};