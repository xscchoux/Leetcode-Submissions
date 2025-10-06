// O(N^2 logN^2) -> O(N^2 logN)
using TIII = tuple<int, int, int>;
class Solution {
public:
    int d[5] = {1, 0, -1, 0, 1};
    int swimInWater(vector<vector<int>>& grid) {
        int N = grid.size(), mx = 0;
        priority_queue<TIII, vector<TIII>, greater<>> pq;
        pq.emplace(grid[0][0], 0, 0);
        vector<vector<bool>> visited(N, vector<bool>(N, false));
        visited[0][0] = true;

        while (!pq.empty()) {
            auto [val, r, c] = pq.top();
            mx = max(val, mx);
            if (r == N-1 && c == N-1) break;
            pq.pop();

            for (int i=0; i<4; i++) {
                int nr = r+d[i], nc = c+d[i+1];
                if (nr < 0 || nr >= N || nc < 0 || nc >= N || visited[nr][nc]) continue;
                visited[nr][nc] = true;
                pq.emplace(grid[nr][nc], nr, nc);
            }
        }

        return mx;
    }
};