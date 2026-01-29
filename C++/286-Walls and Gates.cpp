class Solution {
public:
    int d[5] = {1, 0, -1, 0, 1};
    void wallsAndGates(vector<vector<int>>& rooms) {
        int row = rooms.size(), col = rooms[0].size();
        int INF = 2147483647;
        queue<pair<int, int>> q;

        for (int r=0; r<row; r++) {
            for (int c=0; c<col; c++) {
                if (rooms[r][c] == 0) {
                    q.push({r, c});
                }
            }
        }


        int step = 1;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [currR, currC] = q.front();
                q.pop();
                for (int i=0; i<4; i++) {
                    int nr = currR + d[i], nc = currC + d[i+1];
                    if (nr>=0 && nr<row && nc>=0 && nc<col && rooms[nr][nc] == INF) {
                        rooms[nr][nc] = step;
                        q.push({nr, nc});
                    }
                }
            }
            step++;
        }
    }
};