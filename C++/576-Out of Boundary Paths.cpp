class Solution {
public:
    int kMod = 1e9+7;
    int dp[51][51][51];
    int row, col;
    vector<pair<int, int>> directions;
    int dfs(int r, int c, int move) {
        if (r < 0 || r >= row || c < 0 || c >= col) return 1;
        if (move == 0) return 0;
        if (dp[r][c][move] != -1) return dp[r][c][move];
        
        int ways = 0;
        for (auto [dr, dc]: directions) {
            ways = (ways + dfs(r+dr, c+dc, move-1))%kMod;
        }
        return dp[r][c][move] = ways;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp, -1, sizeof(dp));
        this->directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        this->row = m;
        this->col = n;
        return dfs(startRow, startColumn, maxMove);
    }
};