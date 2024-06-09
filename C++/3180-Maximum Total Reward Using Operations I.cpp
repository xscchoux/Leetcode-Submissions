class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        int N = rewardValues.size(), res = rewardValues[0];
        vector<vector<bool>> dp(N, vector<bool>(2001, false));

        sort(rewardValues.begin(), rewardValues.end());
        dp[0][0] = true;
        dp[0][rewardValues[0]] = true;

        for (int i=1; i<N; i++) {
            for (int val=0; val<2000; val++) {
                if (dp[i-1][val]) {
                    dp[i][val] = dp[i-1][val];
                    if (rewardValues[i] > val) {
                        if (val + rewardValues[i] <= 2000) {
                            dp[i][val+rewardValues[i]] = true;
                        }
                        res = max(res, val+rewardValues[i]);
                    }
                }
            }
        }
        return res;
    }
};