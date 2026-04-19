class Solution {
public:
    int d[5] = {1, 0, -1, 0, 1};
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        sort(begin(sources), end(sources), [](auto &a, auto &b) {
            return a[2] > b[2];
        });
        vector<vector<int>> matrix(n, vector<int>(m, 0));


        deque<array<int, 3>> dq;
        for (int i=0; i<sources.size(); i++) {
            dq.push_back({sources[i][2], sources[i][0], sources[i][1]});
            matrix[sources[i][0]][sources[i][1]] = sources[i][2];
        }

        while (!dq.empty()) {
            int sz = dq.size();
            while (sz-- > 0) {
                auto [color, r, c] = dq.front();
                dq.pop_front();
                for (int i=0; i<4; i++) {
                    int nr = r + d[i], nc = c + d[i+1];
                    if (nr >= 0 && nr < n && nc >= 0 && nc < m && matrix[nr][nc] == 0) {
                        matrix[nr][nc] = color;
                        dq.push_back({color, nr, nc});
                    }
                }
            }
        }

        return matrix;
    }
};