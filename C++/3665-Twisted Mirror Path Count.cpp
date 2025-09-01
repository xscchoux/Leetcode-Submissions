class Solution {
public:
    int kMod = 1e9+7;
    int uniquePaths(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        vector<vector<vector<long long>>> memo(row, vector<vector<long long>>(col, vector<long long>(2, 0)));
        memo[0][0][0] = memo[0][0][1] = 1;

        // memo[r][c][direction], direction 0: move right, 1: move down

        for (int r=0; r<row; r++) {
            for (int c=0; c<col; c++) {
                if (grid[r][c] == 1) {
                    if (r-1 >= 0) {
                        memo[r][c][0] = (memo[r][c][0] + memo[r-1][c][1])%kMod;
                    }
                    if (c-1 >= 0) {
                        memo[r][c][1] = (memo[r][c][1] + memo[r][c-1][0])%kMod;
                    }
                } else {
                    if (r-1 >= 0) {
                        memo[r][c][0] = (memo[r][c][0] + memo[r-1][c][1])%kMod;
                        memo[r][c][1] = (memo[r][c][1] + memo[r-1][c][1])%kMod;
                    }
                    if (c-1 >= 0) {
                        memo[r][c][0] = (memo[r][c][0] + memo[r][c-1][0])%kMod;
                        memo[r][c][1] = (memo[r][c][1] + memo[r][c-1][0])%kMod;
                    }                    
                }
            }
        }
        return memo[row-1][col-1][0];
    }
};