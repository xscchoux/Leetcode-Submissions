class Solution {
public:
    int longestPalindromicSubsequence(string s, int k) {
        int N = s.size();
        vector<vector<vector<int>>> dp(N+1, vector<vector<int>>(N+1, vector<int>(N+1, INT_MAX/2)));
        for (int i=0; i<N; i++) dp[i][i][1] = 0;   // dp[start][end][length] = cost
        int res = 1;

        for (int length=2; length<=N; length++) {
            for (int start=0; start<N; start++) {
                int end = start+length-1;
                if (end >= N) break;
                for (int kk=1; kk<=length; kk++) {
                    // old subsequences
                    dp[start][end][kk] = min(dp[start+1][end][kk], dp[start][end-1][kk]);
                    // new subsequences
                    if (kk > 1) {
                        int plus = min((s[start]-s[end] + 26)%26, (s[end]-s[start] + 26)%26);
                        dp[start][end][kk] = min(dp[start][end][kk], plus + (start+1>end-1? 0:dp[start+1][end-1][kk-2]));

                    }
                }
            }
        }

        for (int start=0; start<N; start++) {
            for (int end=0; end<N; end++) {
                for (int kk=end-start+1; kk>=1; kk--) {
                    if (dp[start][end][kk] <= k) {
                        res = max(res, kk);
                        break;
                    }
                }
            }
        }

        return res;
    }
};