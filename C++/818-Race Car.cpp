// O(target*log(target))
class Solution {
public:
    int racecar(int target) {
        vector<int> dp(target+1, INT_MAX);
        int exp = 0;

        for (int i=0; i<=target; i++) {
            if ( (1<<exp)-1 == i) {
                dp[i] = exp;
                exp++;
                continue;
            }

            int under = (1<<(exp-1)) - 1;
            int over = (1<<exp) - 1;

            // provide dp[i] if going to (1<<(exp-1))-1 and reverse
            for (int p=0; p<exp-1; p++) {
                int backward = (1<<p) - 1;
                dp[i] = min(dp[i], (exp-1) + 1 + dp[backward] + 1 + dp[i-(under-backward)]);
            }
            // min(dp[i] if going to (1<<(exp-1))-1 and reverse, dp[i] if overshoot and reverse)
            dp[i] = min(dp[i], exp + 1 + dp[over-i]);
        }
        return dp[target];
    }
};