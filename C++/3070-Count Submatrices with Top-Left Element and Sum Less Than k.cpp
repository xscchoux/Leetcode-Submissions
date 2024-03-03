class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int row = grid.size(), col = grid[0].size(), res = 0;
        
        for (auto& row:grid) {
            for (int i=1; i<row.size(); i++) {
                row[i] += row[i-1];
            }
        }
        
        for (int c=0; c<col; c++) {
            int tot = 0;
            for (int r=0; r<row; r++) {
                tot += grid[r][c];
                if (tot > k) break;
                res++;
            }
        }
        
        return res;
    }
};