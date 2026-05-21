class Solution {
public:
    vector<pair<int, int>> directions{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int numberOfCleanRooms(vector<vector<int>>& room) {
        int row = room.size(), col = room[0].size();
        vector<vector<bool>> visitedDir(4, vector<bool>(row*col, false));
        vector<bool> visited(row*col, false);
        // right:0, down:1, left:2, up:3

        int r = 0, c = 0, dir = 0;
        visited[0] = true;
        visitedDir[0][0] = true;
        int res = 1;

        while (true) {

            int nr = r + directions[dir].first, nc = c+directions[dir].second;

            if (0<=nr && nr<row && 0<=nc && nc<col && room[nr][nc] == 0) { // can move
                if (visitedDir[dir][nr*col+nc]) break;
                visitedDir[dir][nr*col+nc] = true;
                if (!visited[nr*col+nc]) {
                    visited[nr*col+nc] = true;
                    res++;
                }
                r = nr;
                c = nc;
            } else { // turn 90 degrees
                bool found = false;
                int i;
                for (i=1; i<=3; i++) {
                    if (!visitedDir[(dir+i)%4][r*col+c]) {
                        found = true;
                        break;
                    }
                }
                if (found) {
                    i--;
                    dir = (dir+1)%4;
                    visitedDir[(dir+i)%4][r*col+c] = true;      
                } else {
                    break;
                }
            }
        }
    
        return res;
    }
};