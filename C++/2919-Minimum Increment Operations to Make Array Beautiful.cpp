class Solution {
public:
    long long minIncrementOperations(vector<int>& nums, int k) {
        int N = nums.size();
        vector<long> dp = vector(N, LONG_MAX);
        dp[0] = max(0, k-nums[0]);
        dp[1] = max(0, k-nums[1]);
        dp[2] = max(0, k-nums[2]);
        
        for (int i=3; i<N; i++){
            dp[i] = min(dp[i], max(0, k-nums[i]) + min(dp[i-1], min(dp[i-2], dp[i-3])));
        }

        return *min_element(dp.end()-3, dp.end());
    }
};