class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int N1 = s1.size(), N2 = s2.size();
        // store the ASCII minimum sum of deleted characters for s1[:i+1] and s2[:j+1] in dp[i][j]
        vector<vector<int>> dp(N1+1, vector<int>(N2+1, INT_MAX/2));
        
        dp[0][0] = 0;

        for (int i=1; i<=N1; i++) {
            dp[i][0] = dp[i-1][0] + int(s1[i-1]);
        }

        for (int j=1; j<=N2; j++) {
            dp[0][j] = dp[0][j-1] + int(s2[j-1]);
        }

        for (int i=0; i<N1; i++) {
            for (int j=0; j<N2; j++) {
                if (s1[i] == s2[j]) {
                    dp[i+1][j+1] = dp[i][j];
                } else {
                    dp[i+1][j+1] = min(dp[i+1][j] + int(s2[j]), dp[i][j+1] + int(s1[i]));
                }
            }
        }

        return dp[N1][N2];
    }
};