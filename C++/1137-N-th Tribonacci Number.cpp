class Solution {
    int dp[38];
public:
    int tribonacci(int n) {
        if (dp[n] > 0) return dp[n];
        if (n <= 1) {
            return n;
        } else if (n == 2) {
            return 1;
        } else {
            dp[n] = tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
            return dp[n];
        }
    }
};