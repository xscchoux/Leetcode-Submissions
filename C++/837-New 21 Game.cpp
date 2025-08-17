class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if (k == 0 || k+maxPts <= n) return 1;

        double probSum = 1;  // sum of probability in the window, note that the max window size is maxPts and must only the dp[idx] values where idx < k
        vector<double> dp(n+1, 0);
        dp[0] = 1;

        for (int i=1; i<=n; i++) {
            dp[i] = probSum/maxPts;
            if (i < k) {
                probSum += dp[i];
            }
            if (i-maxPts >= 0 && i-maxPts < k) {  // should keep the window size <= maxPts
                probSum -= dp[i-maxPts];
            }
        }

        return accumulate(begin(dp)+k, end(dp), 0.0);
    }
};