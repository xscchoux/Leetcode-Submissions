class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int row = grid.size(), col = grid[0].size();
        vector<vector<int>> res(row-k+1, vector<int>(col-k+1, INT_MAX));

        for (int r=0; r<row; r++) {
            if (r+k-1 >= row) break;
            for (int c=0; c<col; c++) {
                if (c+k-1 >= col) break;
                vector<int> allNums;
                for (int rr=r; rr <= r+k-1; rr++) {
                    for (int cc=c; cc <= c+k-1; cc++) {
                        allNums.push_back(grid[rr][cc]);
                    }
                }
                sort(begin(allNums), end(allNums));
                int diff = INT_MAX;
                for (int i=1; i<allNums.size(); i++) {
                    if (allNums[i] == allNums[i-1]) continue;
                    diff = min(diff, allNums[i] - allNums[i-1]);
                }
                if (diff == INT_MAX) res[r][c] = 0;
                else res[r][c] = diff;
            }
        }

        return res;
    }
};