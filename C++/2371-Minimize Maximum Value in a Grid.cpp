using TIII = tuple<int, int, int>;
class Solution {
public:
    int d[5] = {0, 1, 0, -1, 0};
    int row, col;
    vector<vector<int>> minScore(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();
        vector<TIII> arr;
        for (int r=0; r<row; r++) {
            for (int c=0; c<col; c++) {
                arr.push_back({grid[r][c], r, c});
            }
        }
        sort(begin(arr), end(arr));
        vector<int> rowVal(row, 0), colVal(col, 0);

        for (auto &[_, r, c]:arr) {
            int curr = max(rowVal[r], colVal[c]);
            rowVal[r] = colVal[c] = curr+1;
            grid[r][c] = curr+1;
        }

        return grid;
    }
};
