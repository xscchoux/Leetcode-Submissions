constexpr const int kMod = 1e9+7;
class Solution {
public:
    int numberOfSets(int n, int k) {

        // dp[index][last segement filled][segments]
        vector<vector<vector<long long>>> dp(n+1, vector<vector<long long>>(2, vector<long long>(k+1, 0)));
        dp[0][0][0] = 1;

        for (int i=1; i<n; i++) {
            for (int kk=0; kk<=k; kk++) {
                dp[i][0][kk] = (dp[i-1][0][kk] + dp[i-1][1][kk])%kMod;

                dp[i][1][kk] = dp[i-1][1][kk];
                if (kk > 0) {
                    dp[i][1][kk] = (dp[i][1][kk] + dp[i-1][0][kk-1] + dp[i-1][1][kk-1])%kMod;
                }
            }
        }

        return (dp[n-1][1][k] + dp[n-1][0][k])%kMod;
    }
};