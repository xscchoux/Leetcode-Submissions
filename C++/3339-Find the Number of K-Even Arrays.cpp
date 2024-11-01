constexpr int kMod = 1e9+7;
using LL = long long;
class Solution {
public:
    int countOfArrays(int n, int m, int k) {
        // (arr[i] * arr[i + 1]) - arr[i] - arr[i + 1] is even => both arr[i] and arr[i+1] must be even
        vector<vector<vector<LL>>> dp(n+1, vector<vector<LL>>(k+1, vector<LL>(2, 0LL)));

        dp[0][0][1] = 1; // Because both dp[i][j][0] and dp[i][j][1] needs dp[i-1][j][1]. This is really tricky

        int nOdd = (m+1)/2, nEven = m/2;

        for (int i=1; i<=n; i++) {
            for (int j=0; j<=k; j++) {
                dp[i][j][0] = ( (j>0?dp[i-1][j-1][0]:0LL) + dp[i-1][j][1] )*nEven%kMod;
                dp[i][j][1] = ( dp[i-1][j][0] + dp[i-1][j][1] )*nOdd%kMod;
            }
        }

        return (dp[n][k][0] + dp[n][k][1])%kMod;
    }
};