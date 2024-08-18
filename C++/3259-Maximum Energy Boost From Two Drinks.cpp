using LL = long long;
class Solution {
public:
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        int N = energyDrinkA.size();
        vector<vector<LL>> dp(N, vector<LL>(2, 0));

        dp[0][0] = energyDrinkA[0];
        dp[0][1] = energyDrinkB[0];

        for (int i=1; i<N; i++) {
            dp[i][0] = energyDrinkA[i] + dp[i-1][0];
            dp[i][1] = energyDrinkB[i] + dp[i-1][1];
            if (i > 1) {
                dp[i][0] = max(dp[i][0], energyDrinkA[i] + dp[i-2][1]);
                dp[i][1] = max(dp[i][1], energyDrinkB[i] + dp[i-2][0]);
            }
        }

        return max(dp[N-1][0], dp[N-1][1]);
    }
};