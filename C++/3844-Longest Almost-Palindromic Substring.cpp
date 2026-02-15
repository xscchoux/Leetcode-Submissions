class Solution {
public:
    int almostPalindromic(string s) {
        int N = s.size(), res = 2;
        vector<vector<int>> dp(N, vector<int>(N, 0));

        for (int i=0; i<N-1; i++) {
            dp[i][i+1] = (s[i] == s[i+1]?0:1);
        }

        for (int len=3; len<=N; len++) {
            for (int i=0; i+len-1<N; i++) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i+1][j-1];
                } else {
                    dp[i][j] = min(dp[i+1][j], dp[i][j-1]) + 1;
                }
                if (dp[i][j] <= 1) {
                    res = max(res, j-i+1);
                }
            }
        }

        return res;
    }
};