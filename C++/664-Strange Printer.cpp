// https://github.com/wisdompeak/LeetCode/tree/master/Dynamic_Programming/664.Strange-Printer
class Solution {
public:
    int strangePrinter(string s) {
        // dp[i][j] = 1 + dp[i+1][j];   // note that we need to handle a special case when k == i
        // dp[i][j] = min { dp[i][k-1] + dp[k+1][j] } // for i<k<j && s[k]==s[i]
        int N = s.size();
        vector<vector<int>> dp(N, vector<int>(N, 0));
        for (int i=0; i<N; i++) dp[i][i] = 1;

        for (int len = 2; len <=N; len++) {
            for (int i=0; i<N; i++) {
                int j = i+len-1;
                if (j >= N) break;
                dp[i][j] = 1 + dp[i+1][j];
                for (int k=i+1; k<=j; k++) {
                    if (s[i] == s[k]) dp[i][j] = min(dp[i][j], dp[i][k-1] + (k+1>j?0:dp[k+1][j]));
                }
            }
        }

        return dp[0][N-1];
    }
};

class Solution {
public:
    int dfs(string& s, int i, int j, vector<vector<int>>& dp) {
        if (j-i+1 <= 1) return j-i+1;
        if (dp[i][j] != -1) return dp[i][j];
        
        // dp[i][j] = 1 + dp[i+1][j];   
        // dp[i][j] = min { dp[i][k-1] + dp[k+1][j] } // for i<k<j && s[k]==s[i]

        int res = 1 + dfs(s, i+1, j, dp);

        for (int k=i+1; k<=j; k++) {
            if (s[i] == s[k]) {
                res = min(res, dfs(s, i, k-1, dp) + dfs(s, k+1, j, dp));
            }
        }

        return dp[i][j] = res;
    }
    int strangePrinter(string s) {
        int N = s.size(), res = 0;
        string newS;
        for (int i=0; i<N; i++) {
            if (i == 0 || s[i] != s[i-1]) {
                newS += s[i];
            }
        }
        vector<vector<int>> dp(N, vector<int>(N, -1));
        return dfs(newS, 0, newS.size()-1, dp);
    }
};