class Solution {
public:
    bool isMagic(vector<vector<int>>& grid, int r, int c) {
        vector<bool> found(9, false);
        for (int rr=r; rr<r+3; rr++) {
            for (int cc=c; cc<c+3; cc++) {
                if (grid[rr][cc] == 0 || grid[rr][cc]>9) return false;
                found[grid[rr][cc]-1] = true;
            }
        }

        for (int i=0; i<9; i++) {
            if (!found[i]) {
                return false;
            }
        }

        int rowSum = 0;
        for (int cc=c; cc<c+3; cc++) rowSum += grid[r][cc];           
        for (int rr = r+1; rr < r+3; rr++) {
            int sum = 0;
            for (int cc=c; cc<c+3; cc++) {
                sum += grid[rr][cc];
            }
            if (sum != rowSum) {
                return false;
            }
        }

        for (int cc = c; cc < c+3; cc++) {
            int sum = 0;
            for (int rr=r; rr<r+3; rr++) {
                sum += grid[rr][cc];
            }
            if (sum != rowSum) {
                return false;
            }
        }

        int diagonalSum = 0;
        for (int rr=r, cc=c; rr<r+3, cc<c+3; rr++, cc++) {
            diagonalSum += grid[rr][cc];
        }
        if (diagonalSum != rowSum) return false;

        int antiDiagonalSum = 0;
        for (int rr=r+2, cc=c; rr>=r, cc<c+3; rr--, cc++) {
            antiDiagonalSum += grid[rr][cc];
        }
        if (antiDiagonalSum != rowSum) return false;

        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size(), res = 0;

        for (int r=0; r<row-2; r++) {
            for (int c=0; c<col-2; c++) {
                if (isMagic(grid, r, c)) res++;
            }
        }

        return res;
    }
};