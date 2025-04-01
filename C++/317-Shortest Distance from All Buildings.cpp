// First AC, brute-force BFS
class Solution {
public:
    int cnt = 0, row, col;
    int d[5] = {1, 0, -1, 0, 1};
    int bfs(int r, int c, vector<vector<int>>& grid, vector<vector<bool>>& visited) {

        visited[r][c] = true;
        queue<pair<int, int>> q;
        q.push({r, c});
        int building = 0, step = 0, tot = 0;

        while (!q.empty()) {
            int sz = q.size();
            while (sz-- > 0) {
                auto [currR, currC] = q.front();
                q.pop();
                for (int i=0; i<4; i++) {
                    int nr = currR+d[i], nc = currC+d[i+1];
                    if (nr>=0 && nr<row && nc>=0 && nc<col && grid[nr][nc] != 2 && !visited[nr][nc]) {
                        visited[nr][nc] = true;
                        if (grid[nr][nc] == 1) {
                            building++;
                            tot += step+1;
                        }
                        else q.push({nr, nc});
                    }
                }
            }
            step++;
        }

        return (building == cnt)? tot:INT_MAX;
    }


    int shortestDistance(vector<vector<int>>& grid) {
        this->row = grid.size();
        this->col = grid[0].size();
        int res = INT_MAX;

        for (int r=0; r<row; r++) {
            for (int c=0; c<col; c++) {
                if (grid[r][c] == 1) cnt++;
            }
        }

        for (int r=0; r<row; r++) {
            for (int c=0; c<col; c++) {
                if (grid[r][c] != 0) continue;
                vector<vector<bool>> visited(row, vector<bool>(col, false));
                res = min(res, bfs(r, c, grid, visited));
            }
        }

        return (res<INT_MAX)?res:-1;
    }
};



// Much faster
class Solution {
public:
    int cnt = 0, row, col;
    int d[5] = {1, 0, -1, 0, 1};
    int shortestDistance(vector<vector<int>>& grid) {
        this->row = grid.size();
        this->col = grid[0].size();
        int res = INT_MAX, one = 0, zero = 0;
        vector<pair<int, int>> buildings;

        for (int r=0; r<row; r++) {
            for (int c=0; c<col; c++) {
                if (grid[r][c] == 1) { 
                    one++;
                    buildings.push_back({r, c});
                }
                else if (grid[r][c] == 0) zero++;
            }
        }

        if (zero == 0) return -1;

        vector<vector<int>> distSum(row, vector<int>(col, 0));
        vector<vector<int>> cnt(row, vector<int>(col, 0));

        for (auto &[R, C]:buildings) {
            queue<pair<int, int>> q;
            q.push({R, C});
            int step = 0;
            vector<vector<bool>> visited(row, vector<bool>(col, false));
            visited[R][C] = true;
            int buildingCnt = 0;

            while (!q.empty()) {
                int sz = q.size();
                while (sz-- > 0) {
                    auto [currR, currC] = q.front();
                    q.pop();
                    for (int i=0; i<4; i++) {
                        int nr = currR+d[i], nc = currC+d[i+1];
                        if (nr>=0 && nr<row && nc>=0 && nc<col && !visited[nr][nc] && grid[nr][nc] != 2) {
                            if (grid[nr][nc] == 1) {
                                buildingCnt++;
                                visited[nr][nc] = true;
                            } else {
                                visited[nr][nc] = true;
                                distSum[nr][nc] += step+1;
                                cnt[nr][nc]++;
                                q.push({nr, nc});
                            }
                        }
                    }
                }
                step++;
            }
            if (buildingCnt + 1 != one) return -1;
        }

        for (int r=0; r<row; r++) {
            for (int c=0; c<col; c++) {
                if (grid[r][c] == 0 && cnt[r][c] == one) {
                    res = min(res, distSum[r][c]);
                }
            }
        }

        return res<INT_MAX?res:-1;
    }
};