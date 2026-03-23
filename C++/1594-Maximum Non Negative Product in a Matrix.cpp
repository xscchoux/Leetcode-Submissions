// Taking modulo in the middle of the computation changes the actual magnitude of numbers, so comparisons like max/min become incorrect.
// Since this DP relies on comparing values (not just their residues), applying modulo early would lead to wrong results.

using LL = long long;
const int kMod = 1e9+7;
class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        vector<vector<LL>> mx(row, vector<LL>(col, LLONG_MIN));
        vector<vector<LL>> mn(row, vector<LL>(col, LLONG_MAX));

        mx[0][0] = mn[0][0] = grid[0][0];

        for (int r=0; r<row; r++) {
            for (int c=0; c<col; c++) {
                if (r == 0 && c == 0) continue;

                if (grid[r][c] < 0) {
                    if (r-1 >= 0) {
                        mn[r][c] = min(mn[r][c], (mx[r-1][c]*grid[r][c]) );
                        mx[r][c] = max(mx[r][c], (mn[r-1][c]*grid[r][c]) );                        
                    }
                    if (c-1 >= 0) {
                        mn[r][c] = min(mn[r][c], (mx[r][c-1]*grid[r][c]) );
                        mx[r][c] = max(mx[r][c], (mn[r][c-1]*grid[r][c]) );                        
                    }
                } else if (grid[r][c] == 0) {
                    mn[r][c] = 0;
                    mx[r][c] = 0;
                } else {
                    if (r-1 >= 0) {
                        mn[r][c] = min(mn[r][c], (mn[r-1][c]*grid[r][c]) );
                        mx[r][c] = max(mx[r][c], (mx[r-1][c]*grid[r][c]) );                        
                    }
                    if (c-1 >= 0) {
                        mn[r][c] = min(mn[r][c], (mn[r][c-1]*grid[r][c]) );
                        mx[r][c] = max(mx[r][c], (mx[r][c-1]*grid[r][c]) );                        
                    }                    
                }

            }
        }

        return mx[row-1][col-1] < 0?-1:mx[row-1][col-1]%kMod;
    }
};