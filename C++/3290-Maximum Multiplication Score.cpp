using LL = long long;
class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b) {
        int N = b.size();
        vector<vector<LL>> dp(5, vector<LL>(N+1, LLONG_MIN/2));  // dp[i][j] is the max value using a[:i+1] and b[:j+1]
        for (int j=0; j<=N; j++) dp[0][j] = 0;

        for (int i=1; i<=4; i++) {
            dp[i][i] = dp[i-1][i-1] + (LL)a[i-1]*b[i-1];
            for (int j = i+1; j<=N; j++) {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j-1] + (LL)a[i-1]*b[j-1]);
            }
        }

        return dp[4][N];
    }
};


// Reduce space complexity, really clever
using LL = long long;
class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b) {
        vector<LL> dp(5, LLONG_MIN/2); // dp[i] is the max value using the first i numbers in a
        dp[0] = 0;

        for (int bb:b) {
            for (int i=4; i>=1; i--) {
                dp[i] = max(dp[i], dp[i-1] + (LL)bb*a[i-1]);
            }
        }

        return dp[4];
    }
};