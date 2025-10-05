using PII = pair<int, int>;
class Solution {
public:
    int d[5] = {0, 1, 0, -1, 0};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int row = heights.size(), col = heights[0].size();
        queue<PII> AtlanticQ, PacificQ;

        vector<vector<bool>> visited(row, vector<bool>(col, false));
        for (int c = 0; c<col; c++) {
            visited[row-1][c] = true;
            AtlanticQ.push({row-1, c});
        }

        for (int r = row-2; r>=0; r--) {
            visited[r][col-1] = true;
            AtlanticQ.push({r, col-1});
        }

        while (!AtlanticQ.empty()) {
            int sz = AtlanticQ.size();
            while (sz--) {
                auto [r, c] = AtlanticQ.front();
                AtlanticQ.pop();
                for (int i=0; i<4; i++) {
                    int nr = r+d[i], nc = c+d[i+1];
                    if (nr<0 || nr >= row || nc<0 || nc>=col || visited[nr][nc]) continue;
                    if (heights[r][c] <= heights[nr][nc]) {
                        visited[nr][nc] = true;
                        AtlanticQ.push({nr, nc});
                    }
                }
            }
        }

        vector<vector<bool>> visited2(row, vector<bool>(col, false));
        for (int c = 0; c<col; c++) {
            visited2[0][c] = true;
            PacificQ.push({0, c});
        }

        for (int r = 1; r<row; r++) {
            visited2[r][0] = true;
            PacificQ.push({r, 0});
        }

        while (!PacificQ.empty()) {
            int sz = PacificQ.size();
            while (sz--) {
                auto [r, c] = PacificQ.front();
                PacificQ.pop();
                for (int i=0; i<4; i++) {
                    int nr = r+d[i], nc = c+d[i+1];
                    if (nr<0 || nr >= row || nc<0 || nc>=col || visited2[nr][nc]) continue;
                    if (heights[r][c] <= heights[nr][nc]) {
                        visited2[nr][nc] = true;
                        PacificQ.push({nr, nc});
                    }
                }
            }
        }

        vector<vector<int>> res;
        for (int r=0; r<row; r++) {
            for (int c=0; c<col; c++) {
                if (visited[r][c] && visited2[r][c]) {
                    res.push_back({r, c});
                }
            }
        }

        return res;
    }
};