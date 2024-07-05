class Solution {
public:
    vector<pair<int, int>> directions;
    Solution () {
        directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    }
    int minFlips(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int res = INT_MAX;
        for (int k = 0; k < (1<<(m*n)); k++) {
            vector<vector<int>> tmp = mat;
            int idx = 0, currK = k;
            while (currK > 0) {
                if (currK%2) {
                    int r = idx/n, c = idx%n;                   
                    tmp[r][c] = (1 - tmp[r][c]);
                    for (auto &[dr, dc]:directions) {
                        int nr = r + dr, nc = c + dc;
                        if (nr>=0 && nr < m && nc>=0 && nc < n) {
                            tmp[nr][nc] = 1 - tmp[nr][nc];
                        }
                    }
                }
                idx++;
                currK = currK/2;
            }
            bool flag = true;
            for (int r=0;r<m;r++) {
                for (int c=0;c<n;c++) {
                    if (tmp[r][c] == 1) {
                        flag = false;
                        break;
                    }
                }
                if (!flag) break;
            }

            if (flag) {
                res = min(res, __builtin_popcount(k));
            }
        }
        return (res < INT_MAX)?res:-1;
    }
};