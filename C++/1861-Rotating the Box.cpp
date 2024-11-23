// First try
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int row = box.size(), col = box[0].size();
        vector<vector<int>> arr;

        for (int r=0; r<row; r++) {
            int right = col-1;
            for (int c=col-1; c>=0; c--) {
                if (box[r][c] == '#') {
                    swap(box[r][c], box[r][right]);
                    right--;
                } else if (box[r][c] == '*') {
                    right = c-1;
                }
            }
        }

        vector<vector<char>> res(col, vector<char>(row));

        // (newR, newC) = (c, row-r-1) => (r, c) = (row-newC-1, newR)

        for (int r=0; r<col; r++) {
            for (int c=0; c<row; c++) {
                res[r][c] = box[row-c-1][r];
            }
        }

        return res;
    }
};


// combine rotation and gravity operations
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int row = box.size(), col = box[0].size();
        vector<vector<char>> res(col, vector<char>(row, '.'));
        // (newR, newC) = (c, row-r-1) => (r, c) = (row-newC-1, newR)

        for (int r=0; r<row; r++) {
            int right = col-1;
            for (int c=col-1; c>=0; c--) {
                int newR = c, newC = row-r-1;
                if (box[r][c] == '#') {
                    res[right][newC] = '#';
                    right--;
                } else if (box[r][c] == '*') {
                    res[newR][newC] = '*';
                    right = c-1;
                }
            }
        }

        return res;
    }
};