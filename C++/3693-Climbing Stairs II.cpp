class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;

        for (int j=1; j<=n; ++j) {
            for (int i=j-1; i>=max(0, j-3); --i) {
                dp[j] = min(dp[j], costs[j-1] + (i-j)*(i-j) + dp[i]);
            }
        }

        return dp.back();
    }
};