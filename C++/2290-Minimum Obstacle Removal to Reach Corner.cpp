using TII = tuple<int, int, int>;
class Solution {
public:
    vector<int> dir = {1, 0, -1, 0, 1};
    int minimumObstacles(vector<vector<int>>& grid) {
        priority_queue<TII, vector<TII>, greater<>> pq;
        pq.push({grid[0][0], 0, 0});
        int row = grid.size(), col = grid[0].size();

        while (!pq.empty()) {
            auto [val, r, c] = pq.top();
            pq.pop();
            // if (grid[r][c] == -1) continue;  // this is not needed because each step is "1"
            // grid[r][c] = -1;
            if (r == row-1 && c == col-1) return val;

            for (int i=0; i<4; i++) {
                int nr = r + dir[i], nc = c + dir[i+1];
                if (0<=nr && nr<row && 0<=nc && nc<col && grid[nr][nc] != -1) {
                    pq.push({val + (grid[nr][nc]==1?1:0), nr, nc});
                    grid[nr][nc] = -1;          // add this line here because each step is "1"
                }
            }
        }

        return -1;
    }
};