// lengthy
class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int row = grid.size(), col = grid[0].size();
        long long kMod = 1e9+7;
        vector<vector<vector<long long>>> dp(row, vector<vector<long long>>(col, vector<long long>(k, 0)));
        dp[0][0][grid[0][0]%k] = 1;

        for (int r=0; r<row; r++) {
            for (int c=0; c<col; c++) {
                if (r == 0 && c == 0) continue;
                else if (r == 0) {
                    for (int v=0; v<k; v++) {
                        int prev = ((v-grid[r][c])%k+k)%k;
                        if (dp[r][c-1][prev] != 0) {
                            dp[r][c][v] = (dp[r][c][v] + dp[r][c-1][prev])%kMod;
                        }
                    }
                } else if (c == 0) {
                    for (int v=0; v<k; v++) {
                        int prev = ((v-grid[r][c])%k+k)%k;
                        if (dp[r-1][c][prev] != 0) {
                            dp[r][c][v] = (dp[r][c][v] + dp[r-1][c][prev])%kMod;
                        }
                    }                    
                } else {

                    for (int v=0; v<k; v++) {
                        int prev = ((v-grid[r][c])%k+k)%k;
                        if (dp[r][c-1][prev] != 0) {
                            dp[r][c][v] = (dp[r][c][v] + dp[r][c-1][prev])%kMod;
                        }
                        if (dp[r-1][c][prev] != 0) {
                            dp[r][c][v] = (dp[r][c][v] + dp[r-1][c][prev])%kMod;
                        }
                    }                     
                }
            }
        }

        return dp[row-1][col-1][0];
    }
};


// Better
class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int row = grid.size(), col = grid[0].size();
        int kMod = 1e9+7;
        vector<vector<int>> dp(col, vector<int>(k, 0));

        int sum = 0;
        for (int c=0; c<col; c++) {
            sum = (sum + grid[0][c])%k;
            dp[c][sum]++;
        }

        for (int r=1; r<row; r++) {
            vector<vector<int>> tmp(col, vector<int>(k, 0));
            for (int c=0; c<col; c++) {
                for (int v=0; v<k; v++) {
                    int prev = ((v-grid[r][c])%k + k)%k;
                    tmp[c][v] = (tmp[c][v] + dp[c][prev])%kMod;
                    if (c > 0) {
                        tmp[c][v] = (tmp[c][v] + tmp[c-1][prev])%kMod;
                    }
                }
            }
            dp = move(tmp);
        }

        return dp[col-1][0];
    }
};