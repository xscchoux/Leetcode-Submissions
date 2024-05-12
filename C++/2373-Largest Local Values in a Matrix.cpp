class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int N = grid.size();
        vector<vector<int>> res(N-2, vector<int>(N-2, 0));

        for (int r=0; r<N-2; r++) {
            for (int c=0; c<N-2; c++) {
                int mxVal = 0;
                for (int rr=r; rr<=r+2; rr++) {
                    for (int cc=c; cc<=c+2; cc++) {
                        mxVal = max(mxVal, grid[rr][cc]);
                    }
                }
                res[r][c] = mxVal;
            }
        }

        return res;
    }
};