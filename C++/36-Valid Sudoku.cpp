class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> row(9, vector<bool>(9, false));
        vector<vector<bool>> col(9, vector<bool>(9, false));
        vector<vector<bool>> block(9, vector<bool>(9, false));

        for (int r=0; r<9; r++) {
            for (int c=0; c<9; c++) {
                if (board[r][c] != '.') {
                    if (!row[r][board[r][c] - '0'-1] && !col[c][board[r][c] - '0'-1] && !block[(r/3)*3 + (c/3)][board[r][c] - '0'-1]) {
                        row[r][board[r][c] - '0'-1] = true;
                        col[c][board[r][c] - '0'-1] = true;
                        block[(r/3)*3 + (c/3)][board[r][c] - '0'-1] = true;
                    } else {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};