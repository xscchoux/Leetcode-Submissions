class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int row = grid.size(), col = grid[0].size(), res = 0;

        vector<vector<int>> preSumX(row+1, vector<int>(col+1, 0));
        vector<vector<int>> preSumY(row+1, vector<int>(col+1, 0));

        for (int r=0; r<row; r++) {
            for (int c=0; c<col; c++) {
                preSumX[r+1][c+1] = preSumX[r+1][c] + preSumX[r][c+1] - preSumX[r][c] + ((grid[r][c] == 'X')?1:0);
                preSumY[r+1][c+1] = preSumY[r+1][c] + preSumY[r][c+1] - preSumY[r][c] + ((grid[r][c] == 'Y')?1:0);
                if (preSumX[r+1][c+1] >= 1 && preSumX[r+1][c+1] == preSumY[r+1][c+1]) res++;
            }
        }
        
        return res;
    }
};