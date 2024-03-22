class Solution {
public:
    int kInversePairs(int n, int k) {
        // Check grandyang, dp[n][k]: number of different arrays that use n numbers and have k inverse pairs 
        // dp[n+1][k] = dp[n][k] + dp[n][k-1] +...+ dp[n][k-n]
        // dp[n+1][k+1] = dp[n][k+1] + dp[n][k] +...+ dp[n][k+1-n]
        // => dp[n+1][k+1] - dp[n+1][k] = dp[n][k+1] - dp[n][k-n]
        // => dp[n+1][k+1] = dp[n+1][k] + dp[n][k+1] - dp[n][k-n]
        // => dp[n+1][k] = dp[n+1][k-1] + dp[n][k] - dp[n][k-1-n]
        // Also dp[i][0] = 1 for all i
        
        vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
        dp[0][0] = 1;
        int kMod = 1e9+7;
        for (int i=1; i<=n; i++) {
            dp[i][0] = 1;
            for (int kk=1; kk<=k; kk++) {
                dp[i][kk] = (dp[i][kk] + dp[i][kk-1] + dp[i-1][kk])%kMod;
                if (kk-1-(i-1) >= 0) {
                    dp[i][kk] = (dp[i][kk] - dp[i-1][kk-1-(i-1)] + kMod)%kMod;
                }
            }
        }
        return dp[n][k];
    }
};