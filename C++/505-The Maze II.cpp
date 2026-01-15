// first AC
class Solution {
public:
    int d[5] = {1, 0, -1, 0, 1};
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int row = maze.size(), col = maze[0].size();
        vector<vector<int>> visited(row, vector<int>(col, INT_MAX));

        queue<tuple<int, int, int>> q;
        q.push({start[0], start[1], 0});
        visited[start[0]][start[1]] = 0;
        
        while (!q.empty()) {
            auto [currR, currC, dist] = q.front();
            q.pop();

            if (currR == destination[0] && currC == destination[1]) {
                visited[currR][currC] = min(visited[currR][currC], dist);
                continue;
            }

            for (int i = 0; i < 4; i++) {
                int nxtR = currR, nxtC = currC;
                while (nxtR >= 0 && nxtR < row && nxtC >= 0 && nxtC < col && maze[nxtR][nxtC] == 0) {
                    nxtR += d[i];
                    nxtC += d[i + 1];
                }
                nxtR -= d[i];
                nxtC -= d[i + 1];
                
                int moved = abs(nxtR-currR) + abs(nxtC-currC);

                if (visited[nxtR][nxtC] > dist + moved) {
                    visited[nxtR][nxtC] = dist + moved;
                    q.push({nxtR, nxtC, dist + moved});
                }
            }
        }


        return visited[destination[0]][destination[1]] == INT_MAX?-1:visited[destination[0]][destination[1]];
    }
};


// Better, with a small modification
class Solution {
public:
    int d[5] = {1, 0, -1, 0, 1};
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int row = maze.size(), col = maze[0].size();
        vector<vector<int>> visited(row, vector<int>(col, INT_MAX));

        queue<tuple<int, int, int>> q;
        q.push({start[0], start[1], 0});
        
        while (!q.empty()) {
            auto [currR, currC, dist] = q.front();
            q.pop();

            if (dist > visited[currR][currC]) continue;   
            // Not dist >= visited[currR][currC] here because we have visited[nxtR][nxtC] = dist + moved below

            if (currR == destination[0] && currC == destination[1]) {
                visited[currR][currC] = min(visited[currR][currC], dist);
                continue;
            }

            for (int i = 0; i < 4; i++) {
                int nxtR = currR, nxtC = currC;
                while (nxtR >= 0 && nxtR < row && nxtC >= 0 && nxtC < col && maze[nxtR][nxtC] == 0) {
                    nxtR += d[i];
                    nxtC += d[i + 1];
                }
                nxtR -= d[i];
                nxtC -= d[i + 1];
                
                int moved = abs(nxtR-currR) + abs(nxtC-currC);

                if (visited[nxtR][nxtC] > dist + moved) {
                    visited[nxtR][nxtC] = dist + moved;
                    q.push({nxtR, nxtC, dist + moved});
                }
            }
        }


        return visited[destination[0]][destination[1]] == INT_MAX?-1:visited[destination[0]][destination[1]];
    }
};