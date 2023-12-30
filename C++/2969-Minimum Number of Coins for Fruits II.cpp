class Solution {
public:
    int minimumCoins(vector<int>& prices) {
        // dp[i][1]: the minimum cost for the 0...i items, where we do pay the ith item
        // dp[i][0]: the minimum cost for the 0...i items, where we do not pay the ith item
        // if ith fruit is free,     dp[i][1] = min(dp[i-1][0], dp[i-1][1]) + prices[i]
        // if ith fruit is not free, dp[i][0] = min(dp[j][1]), where j + j >= i
        
        int N = prices.size();
        deque<int> dq;
        prices.insert(prices.begin(), 0);
        vector<vector<int>> dp(N+1, vector<int>(2, 0));
        dp[1][0] = INT_MAX;
        dp[1][1] = prices[1];
        dq.push_back(1);
        
        for (int i=2; i<=N; i++){
            while (!dq.empty() && dq.front()*2 < i){
                dq.pop_front();
            }
            dp[i][1] = min(dp[i-1][0], dp[i-1][1]) + prices[i];
            dp[i][0] = dp[dq.front()][1];
            while (!dq.empty() && dp[dq.back()][1] >= dp[i][1]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return min(dp[N][1], dp[N][0]);
    }
};