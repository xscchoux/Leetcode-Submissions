class Solution {
public:
    int numberOfWays(int n) {
        // backpack DP
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        int kMod = 1e9+7;

        for (int num:vector<int>{1, 2, 6}) {
            for (int i=num; i<=n; i++) {
                if (i - num < 0) continue;
                dp[i] = (dp[i] + dp[i-num])%kMod;
            }
        }

        if (n >= 4) dp[n] = (dp[n] + dp[n-4])%kMod;
        if (n >= 8) dp[n] = (dp[n] + dp[n-8])%kMod;

        return dp[n];

        // O(1) solution
        // https://leetcode.com/problems/the-number-of-ways-to-make-the-sum/solutions/5303135/python3-o-1-math-sum-of-arithmetic-sequence
        // with 1 :            dp[i] = 1
        // with 1 and 2:       dp[i] = i//2 + 1
        // with 1 and 2 and 6: dp[i] = (dp[i] + (dp[i] - (count-1)*d))*count/2, where d = 3 (dp[i+6] - dp[i]), count = (i//6) + 1
        int kMod = 1e9+7;
        auto f = [] (int n){
            int count = 1 + n/6;
            int last = n/2 + 1;
            return (last + (last - (count-1)*3) )*count/2;
        };

        long long res = f(n)%kMod;
        if (n >= 4) res = (res + f(n-4))%kMod;
        if (n >= 8) res = (res + f(n-8))%kMod;

        return (int)res;
    }
};