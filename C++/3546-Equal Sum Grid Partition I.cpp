class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        long long tot = 0;
        for (int r=0; r<row; r++) {
            for (int c=0; c<col; c++) {
                tot += grid[r][c];
            }
        }

        long long half = 0;
        for (int r=0; r<row; r++) {
            for (int c=0; c<col; c++) {
                half += grid[r][c];
            }
            if (half*2 == tot) return true;
        }

        half = 0;
        for (int c=0; c<col; c++) {
            for (int r=0; r<row; r++) {
                half += grid[r][c];
            }
            if (half*2 == tot) return true;
        }

        return false;
    }
};