using LL = long long;
class Solution {
public:
    int kMod = 1e9+7;
    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        int row = grid.size(), col = grid[0].size();
        vector<vector<vector<LL>>> memo(row, vector<vector<LL>>(col, vector<LL>(16, 0)));
        
        memo[0][0][grid[0][0]] = 1;
        for (int c=1; c<col; c++) {
            for (int kk=0; kk<16; kk++) {
                if (memo[0][c-1][kk] > 0) {
                    int val = grid[0][c]^kk;
                    memo[0][c][val]++;
                }
            }
        }

        for (int r=1; r<row; r++) {
            for (int kk=0; kk<16; kk++) {
                if (memo[r-1][0][kk] > 0) {
                    int val = grid[r][0]^kk;
                    memo[r][0][val]++;
                }
            }
        }

        for (int r=1; r<row; r++) {
            for (int c=1; c<col; c++) {
                for (int kk=0; kk<16; kk++) {
                    if (memo[r-1][c][kk] > 0) {
                        int val = grid[r][c]^kk;
                        memo[r][c][val] = (memo[r][c][val] +memo[r-1][c][kk])%kMod;
                    }
                    if (memo[r][c-1][kk] > 0) {
                        int val = grid[r][c]^kk;
                        memo[r][c][val] = (memo[r][c][val] + memo[r][c-1][kk])%kMod;
                    }
                }       
            }
        }

        return memo[row-1][col-1][k];
    }
};