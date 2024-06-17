class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        int N = power.size();
        sort(power.begin(), power.end());
        vector<long> dp(N+1, 0);
        long maxPre = 0;
        int j = 0;

        for (int i=0; i<N; i++) {
            if (power[i] == power[max(0, i-1)]) {
                dp[i+1] = dp[i] + power[i];
            } else {
                while (power[j] + 2 < power[i]) {
                    maxPre = max(maxPre, dp[j+1]);
                    j++;
                }
                dp[i+1] = power[i] + maxPre;
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};