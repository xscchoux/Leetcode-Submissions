class Solution {
public:
    int maxA(int n) {
        vector<int> dp(n+1, 0);

        for (int i=1; i<=n; i++) {
            dp[i] = dp[i-1] + 1;
            // select, copy, paste
            if (i >= 4) {
                for (int j=1; j<=i-3; j++) {
                    dp[i] = max(dp[i], dp[j] + (i-j-2)*dp[j]);
                }
            }
        }

        return dp[n];
    }
};