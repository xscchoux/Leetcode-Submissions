using TIII = tuple<int, int, int>;
class Solution {
public:
    int d[5] = {1, 0, -1, 0, 1};
    int minimumTime(vector<vector<int>>& grid) {
        if (grid[0][1] > 1 && grid[1][0] > 1) return -1; // cannot move
        int row = grid.size(), col = grid[0].size();
        priority_queue<TIII, vector<TIII>, greater<>> pq;
        pq.emplace(0, 0, 0);
        vector<vector<int>> tGrid(row, vector<int>(col, INT_MAX));

        while (!pq.empty()) {
            auto [t, r, c] = pq.top();
            if (r == row-1 && c == col-1) return t;
            pq.pop();
            if (tGrid[r][c] < INT_MAX) continue;
            tGrid[r][c] = t;

            for (int i=0; i<4; i++) {
                int nr = r+d[i], nc = c+d[i+1];
                if (0<=nr && nr<row && 0<=nc && nc<col && tGrid[nr][nc]==INT_MAX) {
                    int nt = t+1;
                    if (grid[nr][nc] > nt) {
                        nt = grid[nr][nc] + (grid[nr][nc]-nt)%2;
                    }
                    pq.emplace(nt, nr, nc);
                }
            }
        }
        return -1;
    }   
};