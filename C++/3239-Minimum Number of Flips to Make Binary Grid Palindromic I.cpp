class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();

        int res1 = 0, res2 = 0;
        for (int r=0; r<row; r++) {
            int left = 0, right = col-1;
            while (left < right) {
                if (grid[r][left++] != grid[r][right--]) res1++;
            }
        }

        for (int c=0; c<col; c++) {
            int left = 0, right = row-1;
            while (left < right) {
                if (grid[left++][c] != grid[right--][c]) res2++;
            }
        }

        return min(res1, res2);
    }
};