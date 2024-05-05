class Solution {
public:
    int longestIdealString(string s, int k) {
        int N = s.size();
        vector<int> dp(N, 1);
        vector<int> index(26, -1);  // last index of a character
        int res = 1;

        for (int i=0; i<N; i++) {
            int curr = s[i]-'a';
            for (int j=max(0, curr-k); j<=min(curr+k, 25); j++) {
                if (index[j] == -1) continue;
                dp[i] = max(dp[i], dp[index[j]] + 1);
                res = max(dp[i], res);
            }
            index[s[i]-'a'] = i;
        }

        return res;
    }
};