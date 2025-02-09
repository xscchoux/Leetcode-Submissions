class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int N = grid.size();
        unordered_map<int, vector<int>> hmap;
        for (int r=0; r<N; r++) {
            for (int c=0; c<N; c++) {
                hmap[r-c].push_back(grid[r][c]);
            }
        }
        for (auto &[k, v]:hmap) {
            if (k < 0) {
                sort(begin(v), end(v), greater<int>());
            } else {
                sort(begin(v), end(v));
            }
        }

        for (int r=0; r<N; r++) {
            for (int c=0; c<N; c++) {
                grid[r][c] = hmap[r-c].back();
                hmap[r-c].pop_back();
            }
        }

        return grid;
    }
};