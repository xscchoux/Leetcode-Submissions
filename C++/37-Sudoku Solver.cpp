class Solution {
public:
    bool dfs(vector<vector<char>>& board, int r, int c, vector<vector<bool>>& row, vector<vector<bool>>& col, vector<vector<bool>>& block) {
        if (r == 9) {
            return true;
        }

        int nxtR, nxtC;
        if (c+1 == 9) {
            nxtR = r+1;
            nxtC = 0;
        } else {
            nxtR = r;
            nxtC = c+1;
        }

        if (board[r][c] != '.') {
            return dfs(board, nxtR, nxtC, row, col, block);
        } else {
            for (int num=1; num<=9; num++) {
                if (!row[r][num-1] && !col[c][num-1] && !block[(r/3)*3 + (c/3)][num-1]) {
                    row[r][num-1] = true;
                    col[c][num-1] = true;
                    block[(r/3)*3 + (c/3)][num-1] = true;
                    board[r][c] = num+'0';
                    if (dfs(board, nxtR, nxtC, row, col, block)) {
                        return true;
                    }
                    board[r][c] = '.';
                    row[r][num-1] = false;
                    col[c][num-1] = false;
                    block[(r/3)*3 + (c/3)][num-1] = false;
                }
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> row(9, vector<bool>(9, false));
        vector<vector<bool>> col(9, vector<bool>(9, false));
        vector<vector<bool>> block(9, vector<bool>(9, false));

        for (int r=0; r<9; r++) {
            for (int c=0; c<9; c++) {
                if (board[r][c] != '.') {
                    row[r][board[r][c] - '0'-1] = true;
                    col[c][board[r][c] - '0'-1] = true;
                    block[(r/3)*3 + (c/3)][board[r][c] - '0'-1] = true;
                }
            }
        }

        dfs(board, 0, 0, row, col, block);
    }
};