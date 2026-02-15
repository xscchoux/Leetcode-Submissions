class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        int N = nums.size();
        vector<long long> dp(N+1, 0);

        for (int i=0; i<N; i++) {
            if (i > 0 && colors[i] == colors[i-1]) {
                dp[i+1] = max(dp[i], dp[i-1] + nums[i]);
            } else {
                dp[i+1] = dp[i] + nums[i];
            }
        }

        return dp.back();
    }
};