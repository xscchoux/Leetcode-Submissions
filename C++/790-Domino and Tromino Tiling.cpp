class Solution {
public:
    int numTilings(int n) {
        vector<vector<int>> dp(n+1, vector<int>(3, 0)); //  | : 0, L tromino : 1, inversed L tromino : 2
        dp[0][0] = 1;
        int kMod = 1e9+7;
        
        for (int i=1; i<=n; i++) {
            // add a domino file
            dp[i][0] += dp[i-1][0];
            
            // two domino tiles
            if (i >= 2) dp[i][0] = (dp[i][0] + dp[i-2][0])%kMod;

            // add a tromino tile
            if (i >= 2) {
                dp[i][1] = (dp[i][1] + dp[i-2][0])%kMod;
                dp[i][2] = (dp[i][2] + dp[i-2][0])%kMod;
            }

            // add a inversed tromino tile
            dp[i][1] = (dp[i][1] + dp[i-1][2])%kMod;
            dp[i][2] = (dp[i][2] + dp[i-1][1])%kMod;

            // add another tromino to "flat"
            dp[i][0] = (dp[i][0] + dp[i-1][1])%kMod;
            dp[i][0] = (dp[i][0] + dp[i-1][2])%kMod;

        }

        return dp[n][0];
    }
};