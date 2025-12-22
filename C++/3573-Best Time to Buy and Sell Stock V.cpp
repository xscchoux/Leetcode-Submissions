class Solution {
public:
    int N, k;
    long long dfs(int idx, int transaction, int status, vector<int>& prices, vector<vector<vector<long long>>>& dp) {
        if (idx == N) {
            if (status != 0) return LLONG_MIN/2;
            return 0;
        }

        if (dp[idx][transaction][status] != LLONG_MIN) return dp[idx][transaction][status];
        
        long long res = dfs(idx+1, transaction, status, prices, dp);

        if (status == 0) {
            if (transaction < k) {
            // buy
                res = max(res, -1LL*prices[idx] + dfs(idx+1, transaction+1, 1, prices, dp));
            // sell
                res = max(res, 1LL*prices[idx] + dfs(idx+1, transaction+1, 2, prices, dp));
            }
        } else if (status == 1) {
            // sell
            res = max(res, 1LL*prices[idx] + dfs(idx+1, transaction, 0, prices, dp));
        } else {
            // buy back
            res = max(res, -1LL*prices[idx] + dfs(idx+1, transaction, 0, prices, dp));            
        }
        return dp[idx][transaction][status] = res;
    }
    long long maximumProfit(vector<int>& prices, int k) {
        // dp[idx][transactions][status], 0: empty, 1:bought, 2:sell, profit so far
        this->N = prices.size();
        this->k = k;
        vector<vector<vector<long long>>> dp(N, vector<vector<long long>>(k+1, vector<long long>(3, LLONG_MIN)));

        long long res = dfs(0, 0, 0, prices, dp);

        return res;
    }
};

// iterative
class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int N = prices.size();
        vector<vector<vector<long long>>> dp(N, vector<vector<long long>>(k+1, vector<long long>(3, 0)));  // 0: empty, 1:bought, 2:sell, profit so far

        for (int j=1; j<=k; j++) {
            dp[0][j][1] = -prices[0];
            dp[0][j][2] = prices[0];
        }

        for (int i=1; i<N; i++) {
            for (int j=0; j<=k; j++) {
                // empty
                if (j == 0) {
                    dp[i][j][0] = dp[i-1][j][0];
                } else {
                    dp[i][j][0] = max(dp[i-1][j][0], max(dp[i-1][j][1] + prices[i], dp[i-1][j][2] - prices[i]));
                }

                // bought
                if (j > 0) {
                    dp[i][j][1] = max(dp[i-1][j-1][0] - prices[i], dp[i-1][j][1]);
                }

                // sell
                if (j > 0) {
                    dp[i][j][2] = max(dp[i-1][j-1][0] + prices[i], dp[i-1][j][2]);
                }
            }
        }

        return dp[N-1][k][0];
    }
};



// iterative approach with space optimization, much faster
class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int N = prices.size();
        vector<vector<long long>> dp(k+1, vector<long long>(3, 0));  // 0: empty, 1:bought, 2:sell, profit so far

        for (int j=1; j<=k; j++) {
            dp[j][1] = -prices[0];
            dp[j][2] = prices[0];
        }

        for (int i=1; i<N; i++) {
            for (int j=k; j>=0; j--) {
                // empty
                if (j == 0) {
                    dp[j][0] = dp[j][0];
                } else {
                    dp[j][0] = max(dp[j][0], max(dp[j][1] + prices[i], dp[j][2] - prices[i]));
                }

                // bought
                if (j > 0) {
                    dp[j][1] = max(dp[j-1][0] - prices[i], dp[j][1]);
                }

                // sell
                if (j > 0) {
                    dp[j][2] = max(dp[j-1][0] + prices[i], dp[j][2]);
                }
            }
        }

        return dp[k][0];
    }
};