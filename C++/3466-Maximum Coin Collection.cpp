class Solution {
public:
    long long maxCoins(vector<int>& lane1, vector<int>& lane2) {
        // dp[idx][lane num][switches]
        
        int N = lane1.size();
        vector<vector<vector<long long>>> dp(N, vector<vector<long long>>(2, vector<long long>(3, LLONG_MIN/2)));
        dp[0][0][0] = lane1[0];
        dp[0][1][1] = lane2[0];
        
        long long res = max(dp[0][0][0], dp[0][1][1]);
        
        for (int i=1; i<N; i++) {
            for (int k = 0; k<=2; k++) { // num of switches
                // lane1 without switch
                dp[i][0][k] = max((long long)lane1[i], lane1[i] + dp[i-1][0][k]);
                // lane1 with switch
                if (k-1 >= 0) {
                    dp[i][0][k] = max(dp[i][0][k], lane1[i] + dp[i-1][1][k-1]);
                }
                // lane2 without switch
                dp[i][1][k] = (long long)lane2[i] + dp[i-1][1][k];
                // lane2 with switch
                if (k-1 >= 0) {
                    dp[i][1][k] = max({dp[i][1][k], (long long)lane2[i], lane2[i] + dp[i-1][0][k-1]});
                }
                res = max({res, dp[i][0][k], dp[i][1][k]});
            }
        }

        return res;
    }
};