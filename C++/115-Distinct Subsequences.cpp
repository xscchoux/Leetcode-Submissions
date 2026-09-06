class Solution {
public:
    int numDistinct(string s, string t) {
        int Ns = s.size(), Nt = t.size();
        // dp[i][j] : number of distinct subsequences using s[0:i+1] and ends at t[j]
        vector<vector<long long>> dp(Ns, vector<long long>(Nt, 0));

        int cnt = 0;
        for (int i=0; i<Ns; i++) {
            if (s[i] == t[0]) {
                cnt++;
            }
            dp[i][0] = cnt;
        }

        for (int i=1; i<Ns; i++) {
            for (int j=1; j<Nt; j++) {
                // Need this to avoid large numbers
                if (Ns-i  < Nt - j) continue;
                
                if (s[i] == t[j]) {
                    dp[i][j] = dp[i-1][j];
                    dp[i][j] += dp[i-1][j-1];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[Ns-1][Nt-1];
    }
};