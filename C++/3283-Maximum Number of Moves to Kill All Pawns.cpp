// first AC
class Solution {
public:
    int N;
    int dp[16][65536][2];
    vector<pair<int, int>> directions = {{1, 2}, {2, 1}, {1, -2}, {2, -1}, {-1, 2}, {-2, 1}, {-1, -2}, {-2, -1}};
    int bfs(int x, int y, int nx, int ny) {
        queue<pair<int,int>> q;
        q.push({x, y});
        int step = 0;
        unordered_set<int> visited;
        visited.insert(x*50+y);

        while (!q.empty()) {
            int length = q.size();
            while (length-- > 0) {
                auto [currX, currY] = q.front();
                q.pop();
                if (currX == nx && currY == ny) return step;
                for (auto [dx, dy]:directions) {
                    int nX = currX + dx, nY = currY + dy;
                    if (nX >= 0 && nX <= 49 && nY >= 0 && nY <= 49) {
                        if (!visited.contains(nX*50+nY)) {
                            visited.insert(nX*50 + nY);
                            q.push({nX, nY});
                        }
                    }
                }
            }
            step++;
        }

        return step;
    }
    int dfs(int ind, int bitmask, vector<vector<int>>& positions, int isAlice, vector<vector<int>>& dist) {
        if ( bitmask == (1<<N)-1 ) return 0;
        if (dp[ind][bitmask][isAlice] != -1) return dp[ind][bitmask][isAlice];
        int res = (isAlice==1?0:INT_MAX);

        for (int i=0; i<N; i++) {
            if ((bitmask&(1<<i)) == 0) {
                int step = dist[ind][i];
                if (isAlice) {
                    res = max(res, step + dfs(i, bitmask|(1<<i), positions, 1-isAlice, dist));
                } else {
                    res = min(res, step + dfs(i, bitmask|(1<<i), positions, 1-isAlice, dist));
                }
            }
        }

        return dp[ind][bitmask][isAlice] = res;
    }
    int maxMoves(int kx, int ky, vector<vector<int>>& positions) {
        memset(dp, -1, sizeof(dp));
        positions.insert(positions.begin(), 1, {kx, ky});
        this->N = positions.size();
        vector<vector<int>> dist(N, vector<int>(N, 0));

        for (int i=0; i<N; i++) {
            for (int j=i+1; j<N; j++) {
                int d = bfs(positions[i][0], positions[i][1], positions[j][0], positions[j][1]);
                dist[i][j] = d;
                dist[j][i] = d;
            }
        }

        int ans = dfs(0, 1, positions, 1, dist);
        return ans;
    }
};




// minor modification and much better
class Solution {
public:
    int N;
    int dp[16][65536];
    vector<pair<int, int>> directions = {{1, 2}, {2, 1}, {1, -2}, {2, -1}, {-1, 2}, {-2, 1}, {-1, -2}, {-2, -1}};
    int bfs(int x, int y, int nx, int ny) {
        queue<pair<int,int>> q;
        q.push({x, y});
        int step = 0;
        vector<vector<bool>> visited(50, vector<bool>(50, false));
        visited[x][y] = true;

        while (!q.empty()) {
            int length = q.size();
            while (length-- > 0) {
                auto [currX, currY] = q.front();
                q.pop();
                if (currX == nx && currY == ny) return step;
                for (auto [dx, dy]:directions) {
                    int nX = currX + dx, nY = currY + dy;
                    if (nX >= 0 && nX <= 49 && nY >= 0 && nY <= 49 && !visited[nX][nY]) {
                        visited[nX][nY] = true;
                        q.push({nX, nY});
                    }
                }
            }
            step++;
        }

        return step;
    }
    int dfs(int ind, int bitmask, vector<vector<int>>& positions, int isAlice, vector<vector<int>>& dist) {
        if ( bitmask == (1<<N)-1 ) return 0;
        if (dp[ind][bitmask] != -1) return dp[ind][bitmask];
        int res = (isAlice==1?0:INT_MAX);

        for (int i=0; i<N; i++) {
            if ((bitmask&(1<<i)) == 0) {
                int step = dist[ind][i];
                if (isAlice) {
                    res = max(res, step + dfs(i, bitmask|(1<<i), positions, 1-isAlice, dist));
                } else {
                    res = min(res, step + dfs(i, bitmask|(1<<i), positions, 1-isAlice, dist));
                }
            }
        }

        return dp[ind][bitmask] = res;
    }
    int maxMoves(int kx, int ky, vector<vector<int>>& positions) {
        memset(dp, -1, sizeof(dp));
        positions.insert(positions.begin(), 1, {kx, ky});
        this->N = positions.size();
        vector<vector<int>> dist(N, vector<int>(N, 0));

        for (int i=0; i<N; i++) {
            for (int j=i+1; j<N; j++) {
                int d = bfs(positions[i][0], positions[i][1], positions[j][0], positions[j][1]);
                dist[i][j] = d;
                dist[j][i] = d;
            }
        }

        int ans = dfs(0, 1, positions, 1, dist);
        return ans;
    }
};