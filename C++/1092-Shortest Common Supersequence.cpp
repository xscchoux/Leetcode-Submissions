class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int N1 = str1.size(), N2 = str2.size();
        vector<vector<int>> dp(N1+1, vector<int>(N2+1, 0));
        for (int i=0; i<N1; i++) {
            for (int j=0; j<N2; j++) {
                if (str1[i] == str2[j]) {
                    dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + 1);
                } else {
                    dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
        
        string s = "";
        int idx1 = N1, idx2 = N2;

        while (idx1 > 0 && idx2 > 0) {
            if (dp[idx1][idx2] == dp[idx1-1][idx2]) {
                s += str1[idx1-1]; idx1--;
            } else if (dp[idx1][idx2] == dp[idx1][idx2-1]) {
                s += str2[idx2-1]; idx2--;
            } else {
                s += str1[idx1-1];
                idx1--; idx2--;
            }
        }

        return str1.substr(0, idx1) + str2.substr(0, idx2) + string(s.rbegin(), s.rend());
    }
};