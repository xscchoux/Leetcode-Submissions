// O(row*col*(row+col))
class Solution {
public:
    int d[5] = {1, 0, -1, 0, 1};
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int row = maze.size(), col = maze[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));

        queue<pair<int, int>> q;
        q.push({start[0], start[1]});

        while (!q.empty()) {
            auto [currR, currC] = q.front();
            q.pop();
            if (currR == destination[0] && currC == destination[1]) {
                return true;
            }
            for (int i=0; i<4; i++) {
                int nxtR = currR, nxtC = currC;
                while (nxtR >= 0 && nxtR < row && nxtC >= 0 && nxtC < col && maze[nxtR][nxtC] != 1) {
                    nxtR += d[i];
                    nxtC += d[i+1];
                }
                nxtR -= d[i];
                nxtC -= d[i+1];
                if (!visited[nxtR][nxtC]) {
                    visited[nxtR][nxtC] = true;
                    q.push({nxtR, nxtC});
                }
            }
        }

        return false;
    }
};



// Follow-up: print the actual path
class Solution {
public:
    int d[5] = {1, 0, -1, 0, 1};

    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int row = maze.size(), col = maze[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        vector<vector<pair<int,int>>> parent(row, vector<pair<int,int>>(col, {-1, -1}));

        queue<pair<int, int>> q;
        q.push({start[0], start[1]});
        visited[start[0]][start[1]] = true;
        parent[start[0]][start[1]] = {start[0], start[1]};

        while (!q.empty()) {
            auto [currR, currC] = q.front();
            q.pop();

            if (currR == destination[0] && currC == destination[1]) {
                // reconstruct path
                vector<pair<int,int>> path;
                pair<int,int> cur = {currR, currC};
                while (!(cur.first == start[0] && cur.second == start[1])) {
                    path.push_back(cur);
                    cur = parent[cur.first][cur.second];
                }
                path.push_back({start[0], start[1]});
                reverse(path.begin(), path.end());

                for (auto &p : path) {
                    cout << "(" << p.first << "," << p.second << ") ";
                }
                cout << endl;

                return true;
            }

            for (int i = 0; i < 4; i++) {
                int nxtR = currR, nxtC = currC;
                while (nxtR >= 0 && nxtR < row && nxtC >= 0 && nxtC < col
                       && maze[nxtR][nxtC] == 0) {
                    nxtR += d[i];
                    nxtC += d[i + 1];
                }
                nxtR -= d[i];
                nxtC -= d[i + 1];

                if (!visited[nxtR][nxtC]) {
                    visited[nxtR][nxtC] = true;
                    parent[nxtR][nxtC] = {currR, currC}; // ★
                    q.push({nxtR, nxtC});
                }
            }
        }

        return false;
    }
};