class Solution {
public:
    int maxPalindromes(string s, int k) {
        int N = s.size();

        vector<vector<bool>> isPalindrome(N, vector<bool>(N, false));

        for (int i=0; i<N; i++) {
            isPalindrome[i][i] = true;
        }

        for (int len = 2; len <= N; len++) {
            for (int i=0; i + len-1 <= N-1; i++) {
                int j = i + len-1;
                if (s[i] == s[j] && (j == i+1 || isPalindrome[i+1][j-1])) {
                    isPalindrome[i][j] = true;
                }
            }
        }

        vector<int> dp(N+1, 0);  // max number of palindromes in s[0:i+1]

        for (int i=0; i<N; i++) {
            for (int j=i-k+1; j>=0; j--) {
                if (s[i] == s[j] && isPalindrome[j][i]) {
                    dp[i+1] = max(dp[i+1], 1 + dp[j]);
                }
            }
            dp[i+1] = max(dp[i+1], dp[i]);
        }

        return dp[N];
    }
};