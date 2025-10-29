class Solution {
public:
    int countCoprime(vector<vector<int>>& mat) {
        int row = mat.size(), col = mat[0].size();
        int kMod = 1e9+7;

        // dp[row index][gcd]: count
        vector<vector<long long>> dp(row, vector<long long>(151, 0));

        for (int c=0; c<col; c++) {
            dp[0][mat[0][c]]++;
        }

        for (int r=1; r<row; r++) {
            for (int c=0; c<col; c++) {
                for (int val=1; val<=150; val++) {
                    if (dp[r-1][val] == 0) continue;
                    int gcd = __gcd(val, mat[r][c]);
                    dp[r][gcd] = (dp[r][gcd] + dp[r-1][val])%kMod;
                }
            }
        }

        return dp[row-1][1];
    }
};