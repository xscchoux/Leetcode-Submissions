// First AC
using PII = pair<int, int>;
class Solution {
public:
    int dp[501][501][4][2][2];  // dp[r][c][direction][2 or 0][turned]
    int row, col;
    vector<PII> directions = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}}; 
    int dfs(int r, int c, int direction, int leading, int turned, vector<vector<int>>& grid) {

        if (dp[r][c][direction][leading][turned] != -1) return dp[r][c][direction][leading][turned];

        int res = 1;
        if (turned == 0) {
            int newDirection = (direction+1)%4;
            int nr = r + directions[newDirection].first, nc = c + directions[newDirection].second;
            if (nr>=0 && nr<row && nc>=0 && nc<col && grid[nr][nc] == (leading==1?0:2)) {
                res = max(res, 1+dfs(nr, nc, newDirection, 1-leading, 1, grid));
            }            
        }

        int nr = r + directions[direction].first, nc = c + directions[direction].second;
        if (nr>=0 && nr<row && nc>=0 && nc<col && grid[nr][nc] == (leading==1?0:2)) {
            res = max(res, 1+dfs(nr, nc, direction, 1-leading, turned, grid));
        }

        return dp[r][c][direction][leading][turned] = res;
    }
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        this->row = grid.size();
        this->col = grid[0].size();
        bool hasOne = false;
        int res = 1;
        for (int r=0; r<row; r++) {
            for (int c=0; c<col; c++) {
                if (grid[r][c] == 1) {
                    hasOne = true;
                    for (int i=0; i<directions.size(); i++) {
                        int nr = r + directions[i].first, nc = c + directions[i].second;
                        if (nr>=0 && nr<row && nc>=0 && nc<col && grid[nr][nc] == 2) {
                            res = max(res, 1+dfs(nr, nc, i, 1, 0, grid));
                        }
                    }
                }
            }
        }
        if (!hasOne) return 0;
        return res;
    }
};



// a bit better
class Solution {
public:
    vector<pair<int, int>> dirs{{-1, -1}, {-1, 1}, {1, 1}, {1, -1}};
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        int dp[501][501][4][2];
        memset(dp, -1, sizeof(dp));

        // dp[i][j][d][t] is len of longest diagonal segment start from (i, j) to direction[d] with t{0:no turn, 1:turn};
        auto check = [&](int i, int j, int r, int c) -> bool {
            if (r < 0 || r >= n || c < 0 || c >= m)
                return false;
            
            if ((grid[i][j] == 1 && grid[r][c] == 2) ||
                (grid[i][j] == 0 && grid[r][c] == 2) ||
                (grid[i][j] == 2 && grid[r][c] == 0))
                return true;
            return false;
        };
        function<int(int, int, int, int)> dfs = [&](int i, int j, int d, int t) {
            if (dp[i][j][d][t] != -1)
                return dp[i][j][d][t];
            
            int maxlen = 0;
            if (check(i, j, i + dirs[d].first, j + dirs[d].second))
                maxlen = dfs(i + dirs[d].first, j + dirs[d].second, d, t);

            int newd = (d + 1) % 4;
            if (t != 0 && check(i, j, i + dirs[newd].first, j + dirs[newd].second))
                maxlen = max(maxlen, dfs(i + dirs[newd].first, j + dirs[newd].second, newd, t - 1));
            
            return dp[i][j][d][t] = maxlen + 1;
        };

        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    res = max({res, dfs(i, j, 0, 1), dfs(i, j, 1, 1), dfs(i, j, 2, 1), dfs(i, j, 3, 1)});
                }
            }
        }
        return res;
    }
};