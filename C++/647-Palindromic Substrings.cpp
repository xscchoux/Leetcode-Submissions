class Solution {
public:
    int countSubstrings(string s) {
        int N = s.size();
        vector<vector<bool>> dp(N, vector<bool>(N, false));
        int res = 0;
        for (int i=0; i<N; i++) {
            for (int j=0; j<i; j++) {
                if (s[i] == s[j] && (i-1<=j+1 || dp[i-1][j+1])) {
                    dp[i][j] = true;
                    res++;
                }
            }
        }
        return res + N;
    }
};