// First AC, lengthy and slow
class Solution {
public:
    int row, col;
    unordered_set<int> pos;
    bool dfs(int r, int c, int prevR, int prevC, vector<vector<int>>& grid) {
        if (r == row-1 && c == col-1) return true;
        if (pos.contains(r*col+c)) {
            return false;
        }
        pos.insert(r*col+c);
        if (grid[r][c] == 1) {
            if (prevC == c-1) {
                if (c + 1 < col && (grid[r][c+1] == 1 || grid[r][c+1] == 3 || grid[r][c+1] == 5)) {
                    return dfs(r, c+1, r, c, grid);
                } else {
                    return false;
                }
            } else {
                if (c - 1 >= 0 && (grid[r][c-1] == 1 || grid[r][c-1] == 4 || grid[r][c-1] == 6)) {
                    return dfs(r, c-1, r, c, grid);
                } else {
                    return false;
                }                
            }
        } else if (grid[r][c] == 2) {
            if (prevR == r-1) {
                if (r + 1 < row && (grid[r+1][c] == 2 || grid[r+1][c] == 5 || grid[r+1][c] == 6)) {
                    return dfs(r+1, c, r, c, grid);
                } else {
                    return false;
                }
            } else {
                if (r - 1 >= 0 && (grid[r-1][c] == 2 || grid[r-1][c] == 3 || grid[r-1][c] == 4)) {
                    return dfs(r-1, c, r, c, grid);
                } else {
                    return false;
                }                
            }
        } else if (grid[r][c] == 3) {
            if (c-1 == prevC) {
                if (r + 1 < row && (grid[r+1][c] == 2 || grid[r+1][c] == 5 || grid[r+1][c] == 6)) {
                    return dfs(r+1, c, r, c, grid);
                } else {
                    return false;
                }  
            } else {
                if (c - 1 >= 0 && (grid[r][c-1] == 2 || grid[r][c-1] == 5 || grid[r][c-1] == 6)) {
                    return dfs(r, c-1, r, c, grid);
                } else {
                    return false;
                }  
            }
        } else if (grid[r][c] == 4) {
            if (c + 1 == prevC) {
                if (r + 1 < row && (grid[r+1][c] == 2 || grid[r+1][c] == 5 || grid[r+1][c] == 6)) {
                    return dfs(r+1, c, r, c, grid);
                } else {
                    return false;
                }  
            } else { // r + 1 == prevR
                if (c + 1 < col && (grid[r][c+1] == 1 || grid[r][c+1] == 3 || grid[r][c+1] == 5)) {
                    return dfs(r, c+1, r, c, grid);
                } else {
                    return false;
                }  
            }
        } else if (grid[r][c] == 5) {
            if (c - 1 == prevC) {
                if (r - 1 >= 0 && (grid[r-1][c] == 2 || grid[r-1][c] == 3 || grid[r-1][c] == 4)) {
                    return dfs(r-1, c, r, c, grid);
                } else {
                    return false;
                }  
            } else { // r - 1 == prevR
                if (c - 1 >= 0 && (grid[r][c-1] == 1 || grid[r][c-1] == 4 || grid[r][c-1] == 6)) {
                    return dfs(r, c-1, r, c, grid);
                } else {
                    return false;
                }  
            }
        } else {  // group[r][c] == 6
            if (r - 1 == prevR) {
                if (c + 1 < col && (grid[r][c+1] == 1 || grid[r][c+1] == 3 || grid[r][c+1] == 5)) {
                    return dfs(r, c+1, r, c, grid);
                } else {
                    return false;
                }  
            } else { // c + 1 == prevC
                if (r - 1 >= 0 && (grid[r-1][c] == 2 || grid[r-1][c] == 3 || grid[r-1][c] == 4)) {
                    return dfs(r-1, c, r, c, grid);
                } else {
                    return false;
                }  
            }
        }
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        this->row = grid.size();
        this->col = grid[0].size();
        if (row == 1 && col == 1) return true;
        
        bool res = false;
        if (grid[0][0] == 1) {
            res |= dfs(0, 0, 0, -1, grid);
        } else if (grid[0][0] == 2) {
            res |= dfs(0, 0, -1, 0, grid);
        } else if (grid[0][0] == 3) {
            res |= dfs(0, 0, 0, -1, grid);
        } else if (grid[0][0] == 4) {
            res |= dfs(0, 0, 0, 1, grid);
            pos.clear();
            res |= dfs(0, 0, 1, 0, grid);
        } else if (grid[0][0] == 5) {
            return false;
        } else {
            res |= dfs(0, 0, -1, 0, grid);
        }

        return res;
    }
};



// BFS
class Solution {
public:
    // int d[5] = {1, 0, -1, 0, 1};
    bool hasValidPath(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();

        queue<pair<int, int>> q;
        q.push({0, 0});

        unordered_map<int, vector<array<int, 2>>> directions = {
            {1, {{0, -1}, {0, 1}}},
            {2, {{-1, 0}, {1, 0}}},
            {3, {{0, -1}, {1, 0}}},
            {4, {{0, 1}, {1, 0}}},
            {5, {{-1, 0}, {0, -1}}},
            {6, {{-1, 0}, {0, 1}}} 
        };

        vector<vector<bool>> visited(row, vector<bool>(col, false));
        visited[0][0] = true;

        while (!q.empty()) {
            auto [currR, currC] = q.front();
            // cout << currR << currC << endl;
            if (currR == row-1 && currC == col-1) {
                return true;
            }
            q.pop();
            for (auto [dr, dc]:directions[grid[currR][currC]]) {
                int nr = currR + dr, nc = currC + dc;
                if (nr>=0 && nr<row && nc>=0 && nc<col && !visited[nr][nc]) {
                    for (auto [ndr, ndc]:directions[grid[nr][nc]]) {
                        if (nr + ndr == currR && nc + ndc == currC) {
                            visited[nr][nc] = true;
                            q.push({nr, nc});
                        }
                    }
                }
            }
        }

        return false;
    }
};