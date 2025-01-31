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
    int N;
    int d[5] = {1, 0, -1, 0, 1};
    int largestIsland(vector<vector<int>>& grid) {
        this->N = grid.size();
        UnionFind uf(N*N);

        for (int r=0; r<N; r++) {
            for (int c=0; c<N; c++) {
                if (grid[r][c] == 1) {
                    for (int i=0; i<4; i++) {
                        int nr = r+d[i], nc = c+d[i+1];
                        if (nr>=0 && nr<N && nc>=0 && nc<N && grid[nr][nc] == 1) {
                            uf.unite(r*N+c, nr*N+nc);
                        }
                    }
                }
            }
        }

        int res = 0;
        unordered_map<int, int> m; // key:area
        for (int r=0; r<N; r++) {
            for (int c=0; c<N; c++) {
                if (grid[r][c] == 1) {
                    int key = uf.find(r*N+c);
                    if (!m.contains(key)) {
                        int area = dfs(r, c, grid);
                        m[key] = area;
                        res = max(res, area);
                    }
                }
            }
        }

        for (int r=0; r<N; r++) {
            for (int c=0; c<N; c++) {
                if (grid[r][c] != 0) continue;
                unordered_set<int> keys;
                for (int i=0; i<4; i++) {
                    int nr = r+d[i], nc = c+d[i+1];
                    if (nr>=0 && nr<N && nc>=0 && nc<N && grid[nr][nc] == -1) {
                        keys.insert(uf.find(nr*N+nc));
                    }
                }
                int tmp = 1;
                for (auto it=keys.begin(); it != keys.end(); it++) {
                    tmp += m[*it];
                }
                res = max(res, tmp);
            }
        }
        return res;
    }
    int dfs(int r, int c, vector<vector<int>>& grid) {
        if (r==N || c == N || r<0 || c < 0 || grid[r][c] != 1) return 0;
        int res = 1;
        grid[r][c] = -1; // visited
        res += dfs(r, c+1, grid);
        res += dfs(r+1, c, grid);
        res += dfs(r, c-1, grid);
        res += dfs(r-1, c, grid);
        return res;
    }
};