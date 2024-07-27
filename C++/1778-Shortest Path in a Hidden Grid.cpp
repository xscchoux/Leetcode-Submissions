/**
 * // This is the GridMaster's API interface.
 * // You should not implement it, or speculate about its implementation
 * class GridMaster {
 *   public:
 *     bool canMove(char direction);
 *     void move(char direction);
 *     boolean isTarget();
 * };
 */

// 2:target, 1:visited, 0:not visited or can't be visited, -1:start
class Solution {
public:
    int graph[1001][1001] = {};
    vector<pair<char, array<int, 2>>> dirs{{'U', {0, 1}}, {'D', {0, -1}}, {'L', {-1, 0}}, {'R', {1, 0}}};
    unordered_map<char, char> pre{{'U', 'D'}, {'D', 'U'}, {'L', 'R'}, {'R', 'L'}};
    void map(GridMaster &master, int r, int c, char goBack) {
        if (graph[r][c] != -1) graph[r][c] = master.isTarget()? 2: 1;
        for (int i=0; i<dirs.size(); i++) {
            auto &[d, rc] = dirs[i];
            if (graph[r+rc[0]][c+rc[1]] == 0) {
                if (master.canMove(d)) {
                    master.move(d);
                    map(master, r+rc[0], c+rc[1], pre[d]);
                }
            }
        }
        master.move(goBack);
    }
    int findShortestPath(GridMaster &master) {
        graph[500][500] = -1;
        map(master, 500, 500, 'U');

        int step = 0;
        queue<pair<int, int>> q;
        q.push({500, 500});

        while (!q.empty()) {
            int length = q.size();
            while (length-- >0) {
                auto [r, c] = q.front();
                q.pop();
                for (auto &[_, direction]:dirs) {
                    int newR = r+direction[0], newC = c+direction[1];
                    if (newR<0 || newR>1000 || newC<0 || newC>1000 || graph[newR][newC] == 0 || graph[newR][newC] == -1) continue;
                    if (graph[newR][newC] == 2) return step+1;
                    graph[newR][newC] = -1;
                    q.push({newR, newC});
                }
            }
            step++;
        }
        return -1;
    }
};