using TII = tuple<int, int, int, int>;
class Solution {
public:
    vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int step = 0;
        int row = moveTime.size(), col = moveTime[0].size();
        priority_queue<TII, vector<TII>, greater<>> pq;
        pq.push({0, 0, 0, 0});
        vector<vector<int>> visited(row, vector<int>(col, false));

        while (!pq.empty()) {
            auto [time, r, c, parity] = pq.top();
            pq.pop();
            if (r == row-1 && c == col-1) return time;
            if (visited[r][c]) continue;
            visited[r][c] = true;
            for (auto &[dr, dc]:directions) {
                int nr = r+dr, nc = c+dc;
                if (0<=nr && nr<row && 0<=nc && nc<col && !visited[nr][nc]) {
                    pq.push({max(time, moveTime[nr][nc]) + (parity?2:1), nr, nc, 1-parity});
                }
            }
        }
        return -1;
    }
};