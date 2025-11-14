class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (auto &q:queries) {
            int r1 = q[0], r2 = q[2], c1 = q[1], c2 = q[3];
            for (int r=r1; r<=r2; r++) {
                dp[r][c1]++;
                if (c2+1 < n) {
                    dp[r][c2+1]--;
                }  
            }
        }

        vector<vector<int>> res(n, vector<int>(n, 0));

        for (int r=0; r<n; r++) {
            int curr = 0;
            for (int c=0; c<n; c++) {
                curr += dp[r][c];
                res[r][c] = curr;
            }
        }

        return res;
    }
};

// 2D difference, really clever
class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> diff(n+1, vector<int>(n+1, 0)), res(n, vector<int>(n, 0));

        for (auto &q:queries) {
            int r1 = q[0], c1 = q[1], r2 = q[2], c2 = q[3];
            diff[r1][c1]++;
            diff[r1][c2+1]--;
            diff[r2+1][c1]--;
            diff[r2+1][c2+1]++;
        }

        for (int r=0; r<n; r++) {
            for (int c=0; c<n; c++) {
                int x0 = (c==0||r==0)?0:res[r-1][c-1];
                int x1 = (r==0)?0:res[r-1][c];
                int x2 = (c==0)?0:res[r][c-1];
                res[r][c] = diff[r][c] + x1 + x2 - x0;
            }
        }

        return res;
    }
};