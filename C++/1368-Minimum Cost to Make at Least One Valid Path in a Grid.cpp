// Dijkstra 1
using TII = tuple<int, int, int>;
class Solution {
public:
    vector<pair<int, int>> d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int minCost(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        vector<vector<int>> minCost(row, vector<int>(col, INT_MAX));

        priority_queue<TII, vector<TII>, greater<>> pq;
        pq.push({0, 0, 0});

        while (!pq.empty()) {
            auto [cost, currR, currC] = pq.top();
            pq.pop();
            if (currR == row-1 && currC == col-1) return cost;
            if (minCost[currR][currC] < INT_MAX) continue;
            minCost[currR][currC] = cost;

            for (int i=0; i<4; i++) {
                int nr = currR+d[i].first, nc = currC + d[i].second;
                if (nr>=0 && nr<row && nc>=0 && nc<col) {
                    if (grid[currR][currC] == i+1 && minCost[nr][nc] == INT_MAX) {
                        pq.push({cost, nr, nc});
                    } else if (grid[currR][currC] != i+1 && minCost[nr][nc] == INT_MAX) {
                        pq.push({cost+1, nr, nc});
                    }
                }
            }
        }

        return -1;
    }
};


// Dijkstra 2
using TII = tuple<int, int, int>;
class Solution {
public:
    vector<pair<int, int>> d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int minCost(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        vector<vector<int>> minCost(row, vector<int>(col, INT_MAX));

        priority_queue<TII, vector<TII>, greater<>> pq;
        minCost[0][0] = 0;
        pq.push({0, 0, 0});

        while (!pq.empty()) {
            auto [cost, currR, currC] = pq.top();
            pq.pop();
            if (currR == row-1 && currC == col-1) return cost;
            if (cost > minCost[currR][currC]) continue;

            for (int i=0; i<4; i++) {
                int nr = currR+d[i].first, nc = currC+d[i].second;
                if (nr>=0 && nr<row && nc>=0 && nc<col) {
                    if (grid[currR][currC] == i+1 && cost < minCost[nr][nc]) {
                        minCost[nr][nc] = cost;
                        pq.push({cost, nr, nc});
                    } else if (grid[currR][currC] != i+1 && cost+1 < minCost[nr][nc]) {
                        minCost[nr][nc] = cost + 1;
                        pq.push({cost+1, nr, nc});
                    }
                }
            }
        }

        return -1;
    }
};


// 0-1 BFS, used when the difference between the two kind of costs is "1"
using TII = tuple<int, int, int>;
class Solution {
public:
    vector<pair<int, int>> d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int minCost(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        vector<vector<int>> minCost(row, vector<int>(col, INT_MAX));

        deque<TII> dq;
        dq.push_front({0, 0, 0});

        while (!dq.empty()) {
            auto [cost, currR, currC] = dq.front();
            dq.pop_front();
            if (currR == row-1 && currC == col-1) return cost;
            if (minCost[currR][currC] != INT_MAX) continue;
            minCost[currR][currC] = cost;

            for (int i=0; i<4; i++) {
                int nr = currR+d[i].first, nc = currC + d[i].second;
                if (nr>=0 && nr<row && nc>=0 && nc<col) {
                    if (grid[currR][currC] == i+1 && minCost[nr][nc] == INT_MAX) {
                        dq.push_front({cost, nr, nc});
                    } else if (grid[currR][currC] != i+1 && minCost[nr][nc] == INT_MAX) {
                        dq.push_back({cost+1, nr, nc});
                    }
                }
            }
        }

        return -1;
    }
};
