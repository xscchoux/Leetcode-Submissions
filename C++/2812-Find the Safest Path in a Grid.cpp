class Solution {
private:
    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int N = grid.size();
        priority_queue<tuple<int, int, int>, vector<tuple<int ,int, int>>> pq;
        vector<vector<int>> dist(N, vector<int>(N, 0));
        deque<pair<int, int>> dq;
        vector<vector<bool>> visited(N, vector<bool>(N, false));
        int step = 0;

        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                if (grid[i][j] == 1) {
                    dq.push_back({i, j});
                }
            }
        }

        while (!dq.empty()) {
            int length = dq.size();
            while (length-- > 0) {
                auto curr = dq.front();
                dq.pop_front();
                if (visited[curr.first][curr.second]) continue;
                visited[curr.first][curr.second] = true;
                dist[curr.first][curr.second] = step;
                for (auto &[dr, dc]:dir) {
                    int nr = curr.first + dr, nc = curr.second + dc;
                    if (nr < 0 || nr >= N || nc < 0 || nc >= N || visited[nr][nc]) continue;
                    dq.push_back({nr, nc});
                }
            }
            step++;
        }

        pq.push({dist[0][0], 0, 0});
        int res = INT_MAX;

        while (!pq.empty()) {
            auto [val, r, c] = pq.top();
            pq.pop();
            if (grid[r][c] == -1) continue;
            res = min(res, val);
            if (r == N-1 && c == N-1) {
                return res;
            }

            grid[r][c] = -1;
            if (r+1<N && grid[r+1][c]!= -1) pq.push({dist[r+1][c], r+1, c});
            if (r-1>=0 && grid[r-1][c]!= -1) pq.push({dist[r-1][c], r-1, c});
            if (c+1<N && grid[r][c+1] != -1) pq.push({dist[r][c+1], r, c+1});
            if (c-1>=0 && grid[r][c-1] != -1) pq.push({dist[r][c-1], r, c-1});
        }

        return 0;
    }
};