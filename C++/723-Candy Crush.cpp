class Solution {
public:
    int row, col;
    bool remove(vector<vector<int>>& board) {
        set<pair<int, int>> toRemove;

        // find the candies that needed to be crushed
        for (int r=0; r<row; r++) {
            for (int c=1; c<col-1; c++) {
                if (board[r][c] != 0 && board[r][c-1] == board[r][c] && board[r][c] == board[r][c+1]) {
                    toRemove.insert({r, c-1});
                    toRemove.insert({r, c});
                    toRemove.insert({r, c+1});
                }
            }
        }

        for (int c=0; c<col; c++) {
            for (int r=1; r<row-1; r++) {
                if (board[r][c] != 0 && board[r-1][c] == board[r][c] && board[r][c] == board[r+1][c]) {
                    toRemove.insert({r-1, c});
                    toRemove.insert({r, c});
                    toRemove.insert({r+1, c});
                }
            }
        }

        if (toRemove.empty()) {
            return false;
        }

        for (int r=row-1; r>=0; r--) {
            for (int c=col-1; c>=0; c--) {
                if (toRemove.contains({r, c})) {
                    board[r][c] = -1;
                }
            }
        }

        // drop
        for (int c=0; c<col; c++) {
            int rowIdx = row-1;
            for (int r=row-1; r>=0; r--) {
                if (board[r][c] != -1) {
                    board[rowIdx][c] = board[r][c];
                    rowIdx--;
                }
            }
            for (int r=rowIdx; r>=0; r--) {
                board[r][c] = 0;
            }
        }


        return true;
    }
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        this->row = board.size();
        this->col = board[0].size();
        // find -> drop -> find -> drop ...

        while (true) {
            bool res = remove(board);
            if (!res) break;
        }

        return board;
    }
};



// Better, in-place modification
class Solution {
public:
    int row, col;
    bool remove(vector<vector<int>>& board) {
        bool found = false;

        // find the candies that needed to be crushed
        for (int r=0; r<row; r++) {
            for (int c=1; c<col-1; c++) {
                if (board[r][c] != 0 && abs(board[r][c-1]) == abs(board[r][c]) && abs(board[r][c]) == abs(board[r][c+1])) {
                    found = true;
                    board[r][c] = board[r][c-1] = board[r][c+1] = -abs(board[r][c]);
                }
            }
        }

        for (int c=0; c<col; c++) {
            for (int r=1; r<row-1; r++) {
                if (board[r][c] != 0 && abs(board[r-1][c]) == abs(board[r][c]) && abs(board[r][c]) == abs(board[r+1][c])) {
                    found = true;
                    board[r][c] = board[r-1][c] = board[r+1][c] = -abs(board[r][c]);
                }
            }
        }

        if (!found) {
            return false;
        }

        // drop
        for (int c=0; c<col; c++) {
            int rowIdx = row-1;
            for (int r=row-1; r>=0; r--) {
                if (board[r][c] > 0) {
                    board[rowIdx][c] = board[r][c];
                    rowIdx--;
                }
            }
            for (int r=rowIdx; r>=0; r--) {
                board[r][c] = 0;
            }
        }


        return true;
    }
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        this->row = board.size();
        this->col = board[0].size();
        // find -> drop -> find -> drop ...

        while (true) {
            bool res = remove(board);
            if (!res) break;
        }

        return board;
    }
};