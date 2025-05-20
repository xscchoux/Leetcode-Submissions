// Dijkstra
using TIII = tuple<int, int, int>;
class Solution {
public:
    int dir[5] = {1, 0, -1, 0, 1};
    int minMoves(vector<string>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        if (matrix[0][0] == '#') return -1;
        
        priority_queue<TIII, vector<TIII>, greater<>> pq;
        unordered_map<char, vector<pair<int, int>>> hmap;
        for (int r=0; r<row; r++) {
            for (int c=0; c<col; c++) {
                if (isupper(matrix[r][c])) {
                    hmap[matrix[r][c]].push_back({r, c});
                }
            }
        }

        vector<vector<int>> dist(row, vector<int>(col, INT_MAX));
        unordered_set<char> used;
        pq.push({0, 0, 0});

        while (!pq.empty()) {
            auto [d, currR, currC] = pq.top();
            // cout << d << " " << currR << " " << currC << endl;
            pq.pop();
            if (currR == row-1 && currC == col-1) return d;
            if (dist[currR][currC] != INT_MAX) {
                // cout << "continued " << endl;
                continue;
            }
            dist[currR][currC] = d;

            // if this is a character (first visit)
            if (isupper(matrix[currR][currC]) && !used.contains(matrix[currR][currC])) {
                used.insert(matrix[currR][currC]);
                for (auto &[nxtR, nxtC]:hmap[matrix[currR][currC]]) {
                    if (nxtR == currR && nxtC == currC) continue;
                    pq.push({d, nxtR, nxtC});
                }
            }

            for (int i=0; i<4; i++) {
                int nr = currR + dir[i], nc = currC + dir[i+1];
                if (nr>=0 && nr < row && nc >= 0 && nc < col && matrix[nr][nc] != '#' && dist[nr][nc] == INT_MAX) {
                    pq.push({d+1, nr, nc});
                }
            }
        }

        return -1;
    }
};


// 0-1 BFS
using TIII = tuple<int, int, int>;
class Solution {
public:
    int dir[5] = {1, 0, -1, 0, 1};
    int minMoves(vector<string>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        if (matrix[0][0] == '#') return -1;
        
        deque<TIII> dq;

        unordered_map<char, vector<pair<int, int>>> hmap;
        for (int r=0; r<row; r++) {
            for (int c=0; c<col; c++) {
                if (isupper(matrix[r][c])) {
                    hmap[matrix[r][c]].push_back({r, c});
                }
            }
        }

        vector<vector<int>> dist(row, vector<int>(col, INT_MAX));
        unordered_set<char> used;
        dq.push_front({0, 0, 0});

        while (!dq.empty()) {
            auto [d, currR, currC] = dq.front();
            dq.pop_front();

            if (currR == row-1 && currC == col-1) return d;
            if (dist[currR][currC] != INT_MAX) continue;
            dist[currR][currC] = d;

            // if this is a character (first visit)
            if (isupper(matrix[currR][currC]) && !used.contains(matrix[currR][currC])) {
                used.insert(matrix[currR][currC]);
                for (auto &[nxtR, nxtC]:hmap[matrix[currR][currC]]) {
                    if (nxtR == currR && nxtC == currC) continue;
                    dq.push_front({d, nxtR, nxtC});
                }
            }

            for (int i=0; i<4; i++) {
                int nr = currR + dir[i], nc = currC + dir[i+1];
                if (nr>=0 && nr < row && nc >= 0 && nc < col && matrix[nr][nc] != '#' && dist[nr][nc] == INT_MAX) {
                    dq.push_back({d+1, nr, nc});
                }
            }
        }

        return -1;
    }
};