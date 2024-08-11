class Solution {
public:
    int row, col;
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int check(vector<vector<int>>& grid) {
        int cnt = 0;
        vector<vector<int>> visited(row, vector<int>(col, 0));

        for (int r=0; r<row; r++) {
            for (int c=0; c<col; c++) {
                if (grid[r][c] == 1 && !visited[r][c]) {
                    cnt++;
                    if (cnt > 1) return cnt;
                    queue<int> q;
                    q.push(r*col+c);
                    while (!q.empty()) {
                        int length = q.size();
                        while (length-- > 0) {
                            int curr = q.front();
                            q.pop();
                            int r = curr/col, c = curr%col;
                            for (auto &[dr, dc]:directions) {
                                int nr = r+dr, nc = c+dc;
                                if (nr>=0 && nr < row && nc>=0 && nc < col && grid[nr][nc] == 1 && !visited[nr][nc]) {
                                    visited[nr][nc] = 1;
                                    q.push(nr*col+nc);
                                }
                            }
                        }
                    }
                }
            }
        }
        return cnt;
    }
    int minDays(vector<vector<int>>& grid) {
        // Easy to solve once you know that possible answers are : 0, 1, 2
        this->row = grid.size();
        this->col = grid[0].size();
        
        int firstCheck = check(grid);
        if (firstCheck != 1) return 0; 

        for (int r=0; r<row; r++) {
            for (int c=0; c<col; c++) {
                if (grid[r][c] == 1) {
                    grid[r][c] = 0;
                    int island = check(grid);
                    if (island != 1) return 1;
                    grid[r][c] = 1;
                }
            }
        }

        return 2;
    }
};