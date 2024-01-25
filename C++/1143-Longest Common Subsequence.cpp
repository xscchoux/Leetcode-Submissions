class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int N1 = text1.size(), N2 = text2.size();
        vector<vector<int>> dp(N1+1, vector<int>(N2+1, 0));
        
        for (int i=1; i<N1+1; i++) {
            for (int j=1; j<N2+1; j++) {
                if (text1[i-1] == text2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[N1][N2];
    }
};