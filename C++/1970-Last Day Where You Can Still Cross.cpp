class Solution {
public:
    int d[5] = {1, 0, -1, 0, 1};
    bool canCross(int day, int row, int col, vector<vector<int>>& cells) {
        vector<vector<int>> matrix(row, vector<int>(col, 0));

        for (int i=0; i<day; i++) {
            int r = cells[i][0]-1, c = cells[i][1]-1;
            matrix[r][c] = 1;
        }

        queue<pair<int, int>> q;
        for (int c=0; c<col; c++) {
            if (matrix[0][c] == 0) {
                q.push({0, c});
            }
        }

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            if (r == row-1) return true;
            for (int i=0; i<4; i++) {
                int nr = r+d[i], nc = c+d[i+1];
                if (nr>=0 && nr<row && nc>=0 && nc<col && matrix[nr][nc] == 0) {
                    matrix[nr][nc] = -1;
                    q.push({nr, nc});
                }
            }
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {

        int left = 0, right = cells.size()-1;

        while (left + 1 < right) {
            int mid = left + (right-left)/2;
            if (canCross(mid, row, col, cells)) {
                left = mid;
            } else {
                right = mid;
            }
        }

        if (canCross(right, row, col, cells)) {
            return right;
        }

        return left;
    }
};


// UnionFind, clever and pretty fast
// https://leetcode.com/problems/last-day-where-you-can-still-cross/solutions/7452088/dsu-by-la_castille-i3dn
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
    int d[5] = {1, 0, -1, 0, 1};
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        UnionFind uf(row*col+2);
        int N = cells.size();

        vector<vector<int>> matrix(row, vector<int>(col, 1));

        for (int i=N-1; i>=0; i--) {
            int r = cells[i][0]-1, c = cells[i][1]-1;
            matrix[r][c] = 0;
            for (int k=0; k<4; k++) {
                int nr = r+d[k], nc = c+d[k+1];
                if (nr>=0 && nr<row && nc>=0 && nc<col && matrix[nr][nc] == 0) {
                    uf.unite(r*col+c+1, nr*col+nc+1);
                }
            }

            if (r == 0) {
                uf.unite(0, c+1);
            }
            if (r == row-1) {
                uf.unite(row*col+1, r*col+c+1);
            }
            if (uf.find(0) == uf.find(row*col+1)) {
                return i;
            }
        }

        return -1;
    }
};