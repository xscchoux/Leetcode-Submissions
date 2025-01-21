using LL = long long;
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        LL firstRow = accumulate(begin(grid[0]), end(grid[0]), 0LL);
        LL res = LLONG_MAX/2, secondRow = 0;

        for (int i=0; i<grid[0].size(); i++) {
            firstRow -= grid[0][i];
            res = min(res, max(firstRow, secondRow));
            secondRow += grid[1][i];
        }

        return res;
    }
};