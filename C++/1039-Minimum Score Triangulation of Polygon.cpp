class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& dp, vector<int>& values) {
        if (j - i <= 1) return 0;
        int res = INT_MAX;
        for (int k=i+1; k<j; k++) {
            res = min(res, (dp[i][k] == -1?dfs(i, k, dp, values):dp[i][k]) + values[i]*values[k]*values[j] + (dp[k][j] == -1?dfs(k, j, dp, values):dp[k][j]));
        }
        return dp[i][j] = res;
    }
    
    int minScoreTriangulation(vector<int>& values) {
        int N = values.size();
        vector<vector<int>> dp(N, vector<int>(N, -1));
        
        return dfs(0, N-1, dp, values);
    }
};