using LL = long long;
class Solution {
public:
    int kMod = 1e9+7;
    int getSum(vector<int>& nums) {
        int N = nums.size();
        vector<pair<LL, LL>> dp(N); // {preSum of increasing subarray, count of elements}
        LL res = 0;
        
        for (int i=0; i<N; i++) {
            if (i == 0) {
                res = (res + nums[i])%kMod;
                dp[i] = {nums[i], 1};
            } else {
                if (nums[i] == nums[i-1] + 1) {
                    LL tmp = nums[i] + dp[i-1].first + nums[i]*(dp[i-1].second);
                    res = (res + tmp)%kMod;
                    dp[i] = {tmp, 1+dp[i-1].second};
                } else {
                    res = (res + nums[i])%kMod;
                    dp[i] = {nums[i], 1};
                }
            }
        }

        vector<pair<LL, int>> dp2(N); // {preSum of decreasing subarray, count of elements}
        for (int i=0; i<N; i++) {
            if (i == 0) {
                dp2[i] = {nums[i], 1};
            } else {
                if (nums[i] == nums[i-1] - 1) {
                    LL tmp = dp2[i-1].first + nums[i]*(dp2[i-1].second);
                    res = (res + tmp)%kMod;
                    dp2[i] = {nums[i] + tmp, 1+dp2[i-1].second};
                } else {
                    dp2[i] = {nums[i], 1};
                }
            }
        }

        return res;
    }

    // better
    // https://leetcode.com/problems/sum-of-consecutive-subarrays/solutions/5773411/track-sum-and-count/
};