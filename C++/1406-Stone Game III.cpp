class Solution {
public:
    int N;
    int dfs(int idx, vector<int>& stoneValue, vector<int>& dp) {
        if (idx == N) {
            return 0;
        }

        if (dp[idx] != INT_MIN) return dp[idx];

        int score = 0, res = INT_MIN;

        for (int i=idx; i < min(idx+3, N); i++) {
            score += stoneValue[i];
            res = max(res, score - dfs(i+1, stoneValue, dp));
        }


        return dp[idx] = res;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        this->N = stoneValue.size();
        vector<int> dp(N, INT_MIN);

        int res = dfs(0, stoneValue, dp);
        if (res > 0) {
            return "Alice";
        } else if (res == 0) {
            return "Tie";
        } else {
            return "Bob";
        }

    }
};