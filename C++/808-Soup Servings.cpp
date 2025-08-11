class Solution {
public:
    double dfs(int remainA, int remainB, unordered_map<int, unordered_map<int, double>>& dp) {
        if (remainA == 0 && remainB > 0) {
            return 1;
        } else if (remainA == 0 && remainB == 0) {
            return 0.5;
        } else if (remainA > 0 && remainB == 0) {
            return 0;
        } else {
            if (dp[remainA].count(remainB)) return dp[remainA][remainB];
            double res = 0.25*(dfs(max(0, remainA-4), remainB, dp) + dfs(max(0, remainA-3), max(0, remainB-1), dp) + dfs(max(0, remainA-2), max(0, remainB-2), dp) + dfs(max(0, remainA-1), max(0, remainB-3), dp));

            return dp[remainA][remainB] = res;
        }
    }
    double soupServings(int n) {
        int N = ceil(n/25.0);
        unordered_map<int, unordered_map<int, double>> dp;

        for (int i=1; i<=N; i++) {
            if (dfs(i, i, dp) > 1-1e-5) {
                return 1;
            }
        }

        return dfs(N, N, dp);
    }
};