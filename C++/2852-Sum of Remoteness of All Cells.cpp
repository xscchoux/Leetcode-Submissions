using LL = long long;
class Solution {
public:
    int N;
    void dfs(int r, int c, vector<vector<int>>& grid, LL &s, int& cnt) {
        if (r<0 || c<0 || r>=N || c>=N || grid[r][c] == -1) {
            return;
        }
        s += grid[r][c];
        cnt++;
        grid[r][c] = -1;
        dfs(r+1, c, grid, s, cnt);
        dfs(r, c+1, grid, s, cnt);
        dfs(r-1, c, grid, s, cnt);
        dfs(r, c-1, grid, s, cnt);
    }
    long long sumRemoteness(vector<vector<int>>& grid) {
        N = grid.size();
        LL tot = 0, res = 0;
        for (int r=0; r<N; r++) {
            for (int c=0; c<N; c++) {
                if (grid[r][c] != -1) tot += grid[r][c];
            }
        }

        for (int r=0; r<N; r++) {
            for (int c=0; c<N; c++) {
                if (grid[r][c] != -1) {
                    LL sum = 0;
                    int cnt = 0;
                    dfs(r, c, grid, sum, cnt);
                    res += (tot - sum)*cnt;
                }
            }
        }
        return res;
    }
};