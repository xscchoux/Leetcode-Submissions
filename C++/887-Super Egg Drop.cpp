// O(nk), 
class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
        // dp[t][k]: maximum number of floors we can check with t drops and k eggs
        // dp[t][k] = 1 + dp[t-1][k-1] + dp[t-1][k]

        for (int t=1; t<=n; t++) {
            for (int egg=1; egg<=k; egg++) {
                dp[t][egg] = 1 + dp[t-1][egg-1] + dp[t-1][egg];
            }
            if (dp[t][k]>=n) {
                return t;
            }
        }

        return -1;
    }
};



class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<int> dp(k+1);
        // dp[t][k]: maximum number of floors we can check with t drops and k eggs
        // dp[t][k] = 1 + dp[t-1][k-1] + dp[t-1][k]
        // Reduce space complexity, dp[k] += 1- dp[k-1]

        for (int t=1; t<=n; t++) {
            for (int egg=k; egg>0; egg--) {
                dp[egg] += 1 + dp[egg-1];
            }
            if (dp[k] >= n) return t;
        }

        return -1;
    }
};