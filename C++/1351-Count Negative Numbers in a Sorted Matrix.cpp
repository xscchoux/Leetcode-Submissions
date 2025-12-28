class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int col = grid[0].size(), res = 0;

        for (auto &row:grid) {
            int idx = lower_bound(rbegin(row), rend(row), 0) - rbegin(row);
            res += idx;
        }

        return res;
    }
};