class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int tot = accumulate(begin(nums), end(nums), 0);
        if (tot%2) return false;

        int target = tot/2;

        vector<bool> dp(target+1, false);
        dp[0] = true;

        for (int num:nums) {
            for (int t = target; t > 0; t--) {
                if (t - num < 0) break;
                dp[t] = dp[t] || dp[t-num];
            }
        }

        return dp[target];
    }
};