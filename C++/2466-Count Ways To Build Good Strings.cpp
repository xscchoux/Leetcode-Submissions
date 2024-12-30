using LL = long long;
class Solution {
public:
    int kMod = 1e9+7;
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<LL> dp(high+1, 0);
        dp[0] = 1;
        LL res = 0;
        for (int i=1; i<=high; i++) {
            if (i >= zero) {
                dp[i] = (dp[i] + dp[i-zero])%kMod;
            }
            if (i >= one) {
                dp[i] = (dp[i] + dp[i-one])%kMod;
            }
            if (i>=low) {
                res = (res + dp[i])%kMod;
            }
        }
        return res;
    }
};