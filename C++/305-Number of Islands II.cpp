class UnionFind {
    vector<int> parent, rank;
public:
    UnionFind(int n):parent(n) {
        iota(parent.begin(), parent.end(), 0);
        rank.resize(n, 1);
    }
    int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        return find(parent[x]);
    }
    void uni(int x, int y) {
        int px = find(x), py = find(y);
        if (px != py) {
            if (rank[px] > rank[py]) {
                swap(px, py);
            }
            parent[px] = py;
            rank[py] += px;
        }
    }
};

using PII = pair<int, int>;
class Solution {
private:
    vector<PII> directions;
public:
    Solution() {
        directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    }
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        vector<vector<int>> matrix(m, vector<int>(n, 0));
        int curr = 0;
        vector<int> res;
        UnionFind uf(n*m);
        
        for (auto &p:positions) {
            int r = p[0], c = p[1], pos = r*n+c;
            if (matrix[r][c] == 1) {
                res.push_back(curr);
                continue;
            }
            curr++;
            matrix[r][c] = 1;
            for (auto [dr, dc]:directions) {
                int nr = r+dr, nc = c+dc;
                if (nr>=0 && nr<m && nc>=0 && nc<n && matrix[nr][nc] == 1) {
                    int newpos = nr*n + nc;
                    if (uf.find(newpos) != uf.find(pos)) {
                        curr--;
                        uf.uni(newpos, pos);
                    }
                }
            }
            res.push_back(curr);
        }
        return res;
    }
};