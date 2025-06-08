// first AC, O(row*col*energy*states), states is (1<<(number of 'L'))
using TIIII= tuple<int, int, int, int>;
class Solution {
public:
    int d[5] = {1, 0, -1, 0, 1};
    int minMoves(vector<string>& classroom, int energy) {
        int row = classroom.size(), col = classroom[0].size();
        int startR = -1, startC = -1;
        map<pair<int, int>, int> coordToIdx;
        int LNum = -1;

        for (int r=0; r<row; r++) {
            for (int c=0; c<col; c++) {
                if (classroom[r][c] == 'S') {
                    startR = r;
                    startC = c;
                } else if (classroom[r][c] == 'L') {
                    coordToIdx[{r, c}] = ++LNum;
                }
            }
        }

        if (LNum == -1) return 0;
        queue<TIIII> q;
        int state = 0;
        q.push({startR, startC, energy, state});
        vector<vector<vector<vector<int>>>> dist(row, vector<vector<vector<int>>>(col, vector<vector<int>>(energy+1, vector<int>(1<<(LNum+1) , INT_MAX))));
        dist[startR][startC][energy][state] = 0;
        int step = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz-- > 0) {
                auto [currR, currC, remain, state] = q.front();
                q.pop();
                
                if (state == ((1<<(LNum+1))-1)) return step;
                if (remain <= 0) continue;

                for (int i=0; i<4; i++) {
                    int nr = currR + d[i], nc = currC + d[i+1];
                    if (0<=nr && nr<row && 0<=nc && nc<col) {
                        if (classroom[nr][nc] == 'X') continue;
                        else if (classroom[nr][nc] == 'L') {
                            int idx = coordToIdx[{nr, nc}];
                            int newState = state|(1<<idx);
                            if (dist[nr][nc][remain-1][newState] <= step + 1) continue;
                            dist[nr][nc][remain-1][newState] = step + 1;
                            q.push({nr, nc, remain-1, newState});
                        } else if (classroom[nr][nc] == '.' || classroom[nr][nc] == 'S') {
                            if (dist[nr][nc][remain-1][state] <= step + 1) continue;
                            dist[nr][nc][remain-1][state] = step + 1;
                            q.push({nr, nc, remain-1, state});                            
                        } else if (classroom[nr][nc] == 'R') {
                            if (dist[nr][nc][energy][state] <= step + 1) continue;
                            dist[nr][nc][energy][state] = step + 1;
                            q.push({nr, nc, energy, state});                                    
                        }
                    }
                }
            }
            step++;
        }

        return -1;
    }
};

// clever approach, keep maximum energy for each maxE[r][c][state]
using TIIII= tuple<int, int, int, int>;
class Solution {
public:
    int d[5] = {1, 0, -1, 0, 1};
    int minMoves(vector<string>& classroom, int energy) {
        int row = classroom.size(), col = classroom[0].size();
        int startR = -1, startC = -1;
        map<pair<int, int>, int> coordToIdx;
        int LNum = -1;

        for (int r=0; r<row; r++) {
            for (int c=0; c<col; c++) {
                if (classroom[r][c] == 'S') {
                    startR = r;
                    startC = c;
                } else if (classroom[r][c] == 'L') {
                    coordToIdx[{r, c}] = ++LNum;
                }
            }
        }

        if (LNum == -1) return 0;
        queue<TIIII> q;
        int state = 0;
        q.push({startR, startC, energy, state});
        vector<vector<vector<int>>> maxE(row, vector<vector<int>>(col, vector<int>(1<<(LNum+1), -1)));
        maxE[startR][startC][state] = energy;
        int step = 0;

        while (!q.empty()) {
            int sz = q.size();
            while (sz-- > 0) {
                auto [currR, currC, remain, state] = q.front();
                q.pop();
                
                if (state == ((1<<(LNum+1))-1)) return step;
                if (remain <= 0) continue;

                for (int i=0; i<4; i++) {
                    int nr = currR + d[i], nc = currC + d[i+1];
                    if (0<=nr && nr<row && 0<=nc && nc<col) {
                        if (classroom[nr][nc] == 'X') continue;
                        else if (classroom[nr][nc] == 'L') {
                            int idx = coordToIdx[{nr, nc}];
                            int newState = state|(1<<idx);
                            if (maxE[nr][nc][newState] < remain-1) {
                                maxE[nr][nc][newState] = remain-1;
                                q.push({nr, nc, remain-1, newState});
                            }
                        } else if (classroom[nr][nc] == '.' || classroom[nr][nc] == 'S') {
                            if (maxE[nr][nc][state] < remain-1) {
                                maxE[nr][nc][state] = remain-1;
                                q.push({nr, nc, remain-1, state});
                            }                    
                        } else if (classroom[nr][nc] == 'R') {
                            if (maxE[nr][nc][state] < energy) {
                                maxE[nr][nc][state] = energy;
                                q.push({nr, nc, energy, state});
                            }                             
                        }
                    }
                }
            }
            step++;
        }

        return -1;
    }
};