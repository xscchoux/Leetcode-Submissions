class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();

        int res = INT_MIN;
        // single cell intersection (lies strictly within the interior of the grid)
        // If the crossing points cross on a boundary, they are mathematically forced to be a segment with length >= 2
        for (int r=1; r<row-1; r++) {
            for (int c=1; c<col-1; c++) {
                res = max(res, grid[r][c]);
            }
        }

        // horizontal segment with length >= 2
        for (int r=0; r<row; r++) {
            int currSum = grid[r][0];
            for (int c=1; c<col; c++) {
                currSum += grid[r][c];
                res = max(res, currSum);
                currSum = max(currSum, grid[r][c]);
            }
        }


        // vertical segment with length >= 2
        for (int c=0; c<col; c++) {
            int currSum = grid[0][c];
            for (int r=1; r<row; r++) {
                currSum += grid[r][c];
                res = max(res, currSum);
                currSum = max(currSum, grid[r][c]);
            }
        }

        return res;
    }
};