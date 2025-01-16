using PII = pair<int, int>;
class Solution {
    int d[5] = {1, 0, -1, 0, 1};
public:
    int getFood(vector<vector<char>>& grid) {
        int row = grid.size(), col = grid[0].size();
        // find *
        queue<PII> q;
        for (int r=0; r<row; r++) {
            for (int c=0; c<col; c++) {
                if (grid[r][c] == '*') {
                    q.emplace(r, c);
                    grid[r][c] = 'X';
                    break;
                }
            }
        }
        
        // BFS
        int step = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz-- > 0) {
                auto [R, C] = q.front();
                q.pop();
                for (int i=0; i<4; i++) {
                    int nr = R+d[i], nc = C+d[i+1];
                    if (nr<0 || nr==row || nc<0 || nc == col) continue;
                    if (grid[nr][nc] == 'O') {
                        grid[nr][nc] = 'X';
                        q.push({nr, nc});
                    } else if (grid[nr][nc] == '#') {
                        return step + 1;
                    }
                }
            }
            step++;
        }

        return -1;
    }
};