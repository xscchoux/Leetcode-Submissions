using TIII = tuple<int, int, int>;
class Solution {
public:
    int d[5] = {0, 1, 0, -1, 0};
    int trapRainWater(vector<vector<int>>& heightMap) {
        priority_queue<TIII, vector<TIII>, greater<>> pq;
        int row = heightMap.size(), col = heightMap[0].size();
        if (row == 1 || col == 1) return 0;
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        int res = 0;
        // add boundary grids
        // columns
        for (int r=0; r<row; r++) {
            pq.push({heightMap[r][0], r, 0});
            visited[r][0] = true;
            pq.push({heightMap[r][col-1], r, col-1});
            visited[r][col-1] = true;
        }
        // rows
        for (int c=0; c<col; c++) {
            pq.push({heightMap[0][c], 0, c});
            visited[0][c] = true;
            pq.push({heightMap[row-1][c], row-1, c});
            visited[row-1][c] = true;
        }        

        while (!pq.empty()) {
            auto [height, currR, currC] = pq.top();
            pq.pop();

            for (int i=0; i<4; i++) {
                int nr = currR+d[i], nc = currC+d[i+1];
                if (nr<0 || nr>=row || nc<0 || nc>=col || visited[nr][nc]) continue;
                int diff = max(0, height-heightMap[nr][nc]);
                heightMap[nr][nc] += diff;
                res += diff;
                visited[nr][nc] = true;
                pq.push({heightMap[nr][nc], nr, nc});
            }
        }

        return res;
    }
};