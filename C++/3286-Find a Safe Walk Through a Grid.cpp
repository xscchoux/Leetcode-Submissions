using TII = tuple<int, int, int>;
class Solution {
public:
    vector<int> d = {1, 0, -1, 0, 1};
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int row = grid.size(), col = grid[0].size();
        if (grid[0][0] >= health) return false;

        priority_queue<TII, vector<TII>> pq;
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        pq.push({health-grid[0][0], 0, 0});

        while (!pq.empty()) {
            auto [h, r, c] = pq.top();
            pq.pop();
            if (r == row-1 && c == col-1) return true;
            if (visited[r][c]) continue;
            visited[r][c] = true;
            for (int i=0; i<4; i++) {
                int nr = r+d[i], nc = c+d[i+1];
                if (nr>=0 && nc>=0 && nr<row && nc<col && !visited[nr][nc]) {
                    if (grid[nr][nc] == 1 && h-1 > 0) pq.push({h-1, nr, nc});
                    else if (grid[nr][nc] == 0) pq.push({h, nr, nc});
                }
            } 
        }
        return false;
    }
};