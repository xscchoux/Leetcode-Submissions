class Solution {
public:
    int dp[201][201];
    int n, k;
    int dfs(int i, int curr, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore) { // day, city
        if (i == k) return 0;
        if (dp[i][curr] != -1) return dp[i][curr];
        // stay
        int res = stayScore[i][curr] + dfs(i+1, curr, stayScore, travelScore);
        // travel
        for (int nxt=0; nxt<n; nxt++) {
            if (curr == nxt) continue;
            res = max(res, travelScore[curr][nxt] + dfs(i+1, nxt, stayScore, travelScore));
        }
        return dp[i][curr] = res;
    }
    int maxScore(int n, int k, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore) {
        this->k = k;
        this->n = n;
        memset(dp, -1, sizeof(dp));
        int ans = 0;
        for (int i=0; i<n; i++) {
            ans = max(ans, dfs(0, i, stayScore, travelScore));
        }

        return ans;
    }
};