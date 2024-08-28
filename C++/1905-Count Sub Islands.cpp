class Solution {
public:
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int r, int c, bool &valid) {
        if (r<0 || r==grid2.size() || c<0 || c==grid2[0].size() || grid2[r][c] == 0) {
            return;
        }
        if (grid1[r][c] == 0) valid = false;
        grid2[r][c] = 0;
        dfs(grid1, grid2, r+1, c, valid);
        dfs(grid1, grid2, r, c+1, valid);
        dfs(grid1, grid2, r-1, c, valid);
        dfs(grid1, grid2, r, c-1, valid);
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int row = grid1.size(), col = grid1[0].size();
        int res = 0;
        for (int r=0; r<row; r++) {
            for (int c=0; c<col; c++) {
                if (grid2[r][c] == 1) {
                    bool valid = true;
                    dfs(grid1, grid2, r, c, valid);
                    if (valid) {
                        res++;
                    }
                }
            }
        }

        return res;
    }
};