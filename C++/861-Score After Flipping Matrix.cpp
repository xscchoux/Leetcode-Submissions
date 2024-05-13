class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        
        for (auto &g:grid) {
            if (g[0] == 0) {
                for (int c=0; c<col; c++) {
                    g[c] = 1 - g[c];
                }
            }
        }

        int res = 0;
        for (int c=0; c<col; c++) {
            int cnt = 0;
            for (int r=0; r<row; r++) {
                if (grid[r][c] == 1) cnt++;
            }
            res += max(cnt, row-cnt)*(1<<(col-c-1));
        }

        return res;

    }
};