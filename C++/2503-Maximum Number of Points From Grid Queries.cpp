using TIII = tuple<int, int, int>;
class Solution {
public:
    vector<int> d = {1, 0, -1, 0, 1};
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size(), n = grid[0].size();
        vector<pair<int, int>> arr;

        for (int i=0; i<queries.size(); i++) {
            arr.push_back({queries[i], i});
        }

        sort(begin(arr), end(arr));

        priority_queue<TIII, vector<TIII>, greater<>> pq;
        pq.push({grid[0][0], 0, 0});
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[0][0] = true;
        int count = 0;
        vector<int> res(queries.size());

        for (auto &[qVal, idx]:arr) {
            while (!pq.empty()) {
                auto [val, r, c] = pq.top();
                if (val >= qVal) break;
                pq.pop();
                count++;

                for (int i=0; i<4; i++) {
                    int dr = d[i], dc = d[i+1];
                    int nr = r+dr, nc = c+dc;
                    if (nr>=0 && nr<m && nc>=0 && nc<n && !visited[nr][nc]) {
                        pq.push({grid[nr][nc], nr, nc});
                        visited[nr][nc] = true;
                    }
                }
            }
            res[idx] = count;
        }
        return res;
    }
};