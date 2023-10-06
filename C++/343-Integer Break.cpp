class Solution {
public:
    int integerBreak(int n) {
        if (n <= 3) return n-1;
        vector<int> dp(n+1, -1);
        return dfs(dp, n);
    }
    int dfs(vector<int>& dp, int n) {
        if (dp[n] != -1) return dp[n];
        int res = n;
        for (int i = 1; i < n; i++){
            res = max(res, i*dfs(dp, n-i));
        }
        return dp[n] = res;
    }
};