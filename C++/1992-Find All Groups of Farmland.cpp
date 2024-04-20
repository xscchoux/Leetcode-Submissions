class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int row = land.size(), col = land[0].size();
        vector<vector<int>> res;
        
        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                if (land[r][c] == 1) {
                    int nr = r, nc = c;
                    for (nr=r; nr<row && land[nr][c]; nr++) {
                        for (nc=c; nc<col && land[nr][nc]; nc++) {
                            land[nr][nc] = 0;
                        }
                    }
                    res.push_back({r, c, nr-1, nc-1});
                }
            }
        }
        
        return res;
    }
};