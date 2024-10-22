class Solution {
public:
    const vector<pair<int, int>> dir = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
    int m, n;
    bool dfs(int r, int c, vector<vector<int>>& mat, int cnt) {
        if (cnt == m*n-1) return true;
        for (auto [dr, dc]:dir) {
            int nr = r+dr, nc = c+dc;
            if (nr>=0 && nr<m && nc>=0 && nc<n && mat[nr][nc] == -1) {
                mat[nr][nc] = cnt+1;
                if (dfs(nr, nc, mat, cnt+1)) {
                    return true;
                }
                mat[nr][nc] = -1;
            }
        }
        return false;
    }

    vector<vector<int>> tourOfKnight(int m, int n, int r, int c) {
        this->m = m;
        this->n = n;
        vector<vector<int>> mat(m, vector<int>(n, -1));
        mat[r][c] = 0;
        dfs(r, c, mat, 0);

        return mat;
    }
};