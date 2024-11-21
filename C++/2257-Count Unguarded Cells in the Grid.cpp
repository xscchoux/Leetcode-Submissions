class Solution {
public:
    vector<int> dir = {1, 0, -1, 0, 1};
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for (auto &g:guards) {
            visited[g[0]][g[1]] = -2;
        }
        for (auto &w:walls) {
            visited[w[0]][w[1]] = -3;
        }

        for (int r=0; r<m; r++) {
            for (int c=0; c<n; c++) {
                if (visited[r][c] == -2) {
                    for (int i=0; i<4; i++) {
                        int dr = dir[i], dc = dir[i+1];
                        int currR = r, currC = c;
                        while (currR+dr>=0 && currR+dr<m && currC+dc>=0 && currC+dc<n) {
                            currR+=dr;
                            currC+=dc;
                            if (visited[currR][currC] == 0) {
                                visited[currR][currC] = -1;
                            } else if (visited[currR][currC] == -2 || visited[currR][currC] == -3){
                                break;
                            }
                        }
                    }
                }
            }
        }
        int cnt = 0;
        for (int r=0; r<m; r++) {
            for (int c=0; c<n; c++) {
                if (visited[r][c] == 0) cnt++;
            }
        }

        return cnt;
    }
};