class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int row = grid.size(), col = grid[0].size();

        vector<vector<int>> fromN(row, vector<int>(col, 0));
        for (int r=0; r<row; r++) {
            for (int c=0; c<col; c++) {
                if (grid[r][c] == 'E') {
                    fromN[r][c] = (r==0?1:(fromN[r-1][c] + 1));
                } else if (grid[r][c] == 'W') {
                    fromN[r][c] = 0;
                } else {
                    fromN[r][c] = (r==0?0:fromN[r-1][c]);
                }
            }
        }

        vector<vector<int>> fromS(row, vector<int>(col, 0));
        for (int r=row-1; r>=0; r--) {
            for (int c=0; c<col; c++) {
                if (grid[r][c] == 'E') {
                    fromS[r][c] = ((r==row-1)?1:(fromS[r+1][c] + 1));
                } else if (grid[r][c] == 'W') {
                    fromS[r][c] = 0;
                } else {
                    fromS[r][c] = ((r==row-1)?0:fromS[r+1][c]);
                }
            }
        }

        vector<vector<int>> fromE(row, vector<int>(col, 0));
        for (int r=0; r<row; r++) {
            for (int c=col-1; c>=0; c--) {
                if (grid[r][c] == 'E') {
                    fromE[r][c] = ((c==col-1)?1:(fromE[r][c+1] + 1));
                } else if (grid[r][c] == 'W') {
                    fromE[r][c] = 0;
                } else {
                    fromE[r][c] = ((c==col-1)?0:(fromE[r][c+1]));
                }
            }
        }

        vector<vector<int>> fromW(row, vector<int>(col, 0));
        for (int r=0; r<row; r++) {
            for (int c=0; c<col; c++) {
                if (grid[r][c] == 'E') {
                    fromW[r][c] = ((c==0)?1:(fromW[r][c-1] + 1));
                } else if (grid[r][c] == 'W') {
                    fromW[r][c] = 0;
                } else {
                    fromW[r][c] = ((c==0)?0:(fromW[r][c-1]));
                }
            }
        }

        int res = 0;
        for (int r=0; r<row; r++) {
            for (int c=0; c<col; c++) {
                if (grid[r][c] == '0') {
                    res = max(res, fromN[r][c] + fromS[r][c] + fromW[r][c] + fromE[r][c]);
                }
            }
        }

        return res;
    }
};