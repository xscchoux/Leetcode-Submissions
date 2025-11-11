// O(L*m*n), 2D knapsack DP
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int N = strs.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        int res = 0;

        for (int i=0; i<N; i++) {
            // count 0 and 1
            int cnt[2] = {};
            for (char c:strs[i]) {
                cnt[c-'0']++;
            }

            for (int mm=m-cnt[0]; mm>=0; mm--) {
                for (int nn=n-cnt[1]; nn>=0; nn--) {
                    dp[mm+cnt[0]][nn+cnt[1]] = max(dp[mm+cnt[0]][nn+cnt[1]], 1 + dp[mm][nn]);
                    res = max(res, dp[mm+cnt[0]][nn+cnt[1]]);
                }
            }
        }
    
        return res;
    }
};