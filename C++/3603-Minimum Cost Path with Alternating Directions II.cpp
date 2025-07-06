using LL = long long;
class Solution {
public:
    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        if (m == 1 && n == 1) return 1;

        int row = m, col = n;
        vector<vector<LL>> minCost(row, vector<LL>(col, LLONG_MAX));
        minCost[0][0] = 1;

        for (int r=0; r<row; r++) {
            for (int c=0; c<col; c++) {
                if (r == 0 && c == 0) continue;
                else if (r == 0) {
                    minCost[r][c] = minCost[r][c-1] + (r+1)*(c+1) + waitCost[r][c];
                } else if (c == 0) {
                    minCost[r][c] = minCost[r-1][c] + (r+1)*(c+1) + waitCost[r][c];
                } else {
                    minCost[r][c] = min(minCost[r-1][c], minCost[r][c-1]) + (r+1)*(c+1) + waitCost[r][c]; 
                }
            }
        }
        
        return minCost[row-1][col-1] - waitCost[row-1][col-1];
    }
};