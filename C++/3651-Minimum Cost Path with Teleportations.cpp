const int kMod = 1e9+7;

// https://leetcode.com/problems/minimum-cost-path-with-teleportations/solutions/7530384/dp-suffix-min-for-teleport159ms-beats-92-8vg9/?envType=daily-question&envId=2026-01-28
class Solution {
public:
    static inline int pos(int r, int c, int col) {
        return r*col + c;
    }
    int minCost(vector<vector<int>>& grid, int k) {
        int row = grid.size(), col = grid[0].size(), rc = row*col;
        vector<vector<int>> minCost(k+1, vector<int>(rc+1, INT_MAX));
        minCost[0][0] = 0;
        map<int, vector<int>, greater<>> valPos;
        vector<int> valCost(10001, INT_MAX);  // grid val : minimum cost to reach this grid

        // without teleportations
        for (int r=0; r<row; r++) {
            for (int c=0; c<col; c++) {
                int rcPos = pos(r, c, col);
                if (r > 0) {
                    int prevPos = pos(r-1, c, col);
                    minCost[0][rcPos] = min(minCost[0][rcPos], minCost[0][prevPos] + grid[r][c]);
                }
                if (c > 0) {
                    int prevPos = pos(r, c-1, col);
                    minCost[0][rcPos] = min(minCost[0][rcPos], minCost[0][prevPos] + grid[r][c]);
                }
                valPos[grid[r][c]].push_back(rcPos);
            }
        }

        // layered DP
        for (int kk=1; kk<=k; kk++) {
            // update valCost ( after all possible teleportation )
            int minVal = INT_MAX;
            for (auto &[key, posVec]:valPos) {
                for (int rcPos:posVec) {
                    minVal = min(minVal, minCost[kk-1][rcPos]);
                }
                valCost[key] = minVal;
            }

            // update minCost (with or without teleportation)
            for (int r=0; r<row; r++) {
                for (int c=0; c<col; c++) {
                    int currPos = pos(r, c, col);
                    minCost[kk][currPos] = min(minCost[kk-1][currPos], valCost[grid[r][c]]);
                }
            }

            // normal move
            for (int r=0; r<row; r++) {
                for (int c=0; c<col; c++) {
                    int rcPos = pos(r, c, col);
                    if (r > 0) {
                        int prevPos = pos(r-1, c, col);
                        minCost[kk][rcPos] = min(minCost[kk][rcPos], minCost[kk][prevPos] + grid[r][c]);
                    }
                    if (c > 0) {
                        int prevPos = pos(r, c-1, col);
                        minCost[kk][rcPos] = min(minCost[kk][rcPos], minCost[kk][prevPos] + grid[r][c]);
                    }
                }
            }            
        }

        return minCost[k][pos(row-1, col-1, col)];
    }
};