// O(row*col*(row+col-1))
using LL = long long;
class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int row = grid.size(), col = grid[0].size();
        int sideSum = row + col-1;
        if (sideSum%2 == 1) return false;  
        int mx = sideSum/2;
        vector<vector<vector<bool>>> cnt(row+1, vector<vector<bool>>(col+1, vector<bool>(1 + mx, false)));
        cnt[0][1][0] = true;
        cnt[1][0][0] = true;

        for (int r=0; r<row; r++) {
            for (int c=0; c<col; c++) {
                for (int val = 0; val <= mx; val++) {
                    // from above
                    if (grid[r][c] == '(' && val + 1 <= mx && sideSum - (r+c+1) >= val+1 && cnt[r][c+1][val]) {
                        cnt[r+1][c+1][val+1] = true;
                    } else if (grid[r][c] == ')' && val-1 >= 0 && cnt[r][c+1][val]) {
                        cnt[r+1][c+1][val-1] = true;
                    }

                    // from left
                    if (grid[r][c] == '(' && val + 1 <= mx && sideSum - (r+c+1) >= val+1 && cnt[r+1][c][val]) {
                        cnt[r+1][c+1][val+1] = true;
                    } else if (grid[r][c] == ')' && val-1 >= 0 && cnt[r+1][c][val]) {
                        cnt[r+1][c+1][val-1] = true;
                    }

                }
            }
        }

        return cnt[row][col][0];
    }
};