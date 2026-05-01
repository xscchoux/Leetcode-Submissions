// First AC, lengthy and slow
class Solution {
public:
    int d[5] = {0, 1, 0, -1, 0};
    int row, col;
    bool dfs(int r, int c, int cnt, int prevR, int prevC, char currChar, vector<vector<char>>& grid, unordered_set<int>& visited) {
        grid[r][c] = '#';
        visited.insert(r*col+c);

        for (int i=0; i<4; i++) {
            int nr = r + d[i], nc = c + d[i+1];
            if (!(nr == prevR && nc == prevC) && nr>=0 && nr<row && nc>=0 && nc<col && visited.contains(nr*col+nc) && cnt >= 4) {
                return true;
            }
            if (nr>=0 && nr<row && nc>=0 && nc<col && grid[nr][nc] == currChar) {
                grid[nr][nc] = '#';
                if (dfs(nr, nc, cnt+1, r, c, currChar, grid, visited)){
                    return true;
                }
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        this->row = grid.size();
        this->col = grid[0].size();
        
        for (int r=0; r<row; r++) {
            for (int c=0; c<col; c++) {
                if (grid[r][c] == '#') continue;
                unordered_set<int> visited;
                if (dfs(r, c, 1, -1, -1, grid[r][c], grid, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
};




// Better DFS. Another way to use visited. No need to count elements in paths
class Solution {
public:
    int d[5] = {0, 1, 0, -1, 0};
    int row, col;
    bool dfs(int r, int c, int prevR, int prevC, char currChar, vector<vector<char>>& grid, vector<vector<int>>& visited) {
        bool res = false;
        for (int i=0; i<4; i++) {
            int nr = r + d[i], nc = c + d[i+1];
            if (!(nr == prevR && nc == prevC) && nr>=0 && nr<row && nc>=0 && nc<col) {
                if (visited[nr][nc] == -1*(int)currChar) {
                    return true;
                }
                if (grid[nr][nc] == currChar) {
                    visited[nr][nc] = -1*(int)currChar;
                    if (dfs(nr, nc, r, c, currChar, grid, visited)) {
                        return true;
                    }
                }
            }
        }
        return res;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        this->row = grid.size();
        this->col = grid[0].size();

        vector<vector<int>> visited(row, vector<int>(col, 0));

        for (int r=0; r<row; r++) {
            for (int c=0; c<col; c++) {
                visited[r][c] = (int)grid[r][c];
            }
        }

        for (int r=0; r<row; r++) {
            for (int c=0; c<col; c++) {
                if (visited[r][c] < 0) continue;
                visited[r][c] = -visited[r][c];
                if (dfs(r, c, -1, -1, grid[r][c], grid, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
};



// Union-Find, fastest, not easy
struct UnionFind {
    vector<int> parent, rank;
    explicit UnionFind(int n) : parent(vector<int>(n)), rank(vector<int>(n, 1)) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int node) {
        if(node == parent[node]) return node;
        return parent[node] = find(parent[node]);
    }
    bool unite(int node1, int node2) {
        int p1 = find(node1);
        int p2 = find(node2);
        if(p1 == p2) return false; // Same parent
        if(rank[p1] >= rank[p2]) {
            // Append p2 under p1
            parent[p2] = p1;
            rank[p1] += rank[p2];
        }else {
            parent[p1] = p2;
            rank[p2] += rank[p1];
        }
        return true;
    }
};


class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int row = grid.size(), col = grid[0].size();
        if (row == 1 || col == 1) return false;  // not necessary
        UnionFind uf(row*col);

        for (int r=0; r<row-1; r++) {
            for (int c=0; c<col-1; c++) {
                // look down
                if (grid[r][c] == grid[r+1][c]) {
                    uf.unite(r*col+c, (r+1)*col + c);
                }
                // look right
                if (grid[r][c] == grid[r][c+1]) {
                    if (uf.find(r*col+c) == uf.find(r*col+c+1)) {
                        return true;
                    }
                    uf.unite(r*col+c, r*col+c+1);
                }
            }
            // look down again
            if (grid[r][col-1] == grid[r+1][col-1]) {
                uf.unite(r*col + (col-1), (r+1)*col + (col-1));
            }
        }

        // look right in the last row
        for (int c=0; c<col-1; c++) {
            if (uf.find((row-1)*col+c) == uf.find((row-1)*col+c+1)) {
                return true;
            }
            uf.unite((row-1)*col+c, (row-1)*col+c+1);
        }

        return false;
    }
};