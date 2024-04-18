class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int cnt = 0;
        unordered_set<int> s;
        int row = grid.size(), col = grid[0].size();
        
        function<void(int, int)> dfs = [&](int r, int c) {
            if (s.contains(r*col+c)) return;
            s.insert(r*col+c);
            if (r-1 >= 0 && grid[r-1][c] == 1) {
                dfs(r-1, c);
            } else {
                cnt++;
            }

            if (r+1 < row && grid[r+1][c] == 1) {
                dfs(r+1, c);
            } else {
                cnt++;
            }

            if (c+1 < col && grid[r][c+1] == 1) {
                dfs(r, c+1);
            } else {
                cnt++;
            }

            if (c-1 >= 0 && grid[r][c-1] == 1) {
                dfs(r, c-1);
            } else {
                cnt++;
            }
        };
        
        bool found = false;
        for (int r=0; r<row; r++) {
            for (int c=0; c<col; c++) {
                if (grid[r][c] == 1) {
                    dfs(r, c);
                    found = true;
                    break;
                }
            }
            if (found) break;
        }
        
        return cnt;
    }
};