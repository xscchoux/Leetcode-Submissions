class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int N = s.size();
        vector<int> dp(N+1, 0);
        for (auto &s:shifts) {
            int u = s[0], v = s[1], w = s[2];
            if (w == 0) {
                dp[u]--;
                dp[v+1]++;
            }  else {
                dp[u]++;
                dp[v+1]--;
            }
        }

        int running = 0;
        for (int i=0; i<N; i++) {
            running += dp[i];
            s[i] = ( (s[i] - 'a' + running)%26 + 26)%26 + 'a';
        }

        return s;
    }
};