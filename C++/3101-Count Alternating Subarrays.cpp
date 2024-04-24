using LL = long long;
class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        int N = nums.size();
        vector<LL> dp(N, 1);
        
        for (int i=1; i<N; i++) {
            if (nums[i] != nums[i-1]) {
                dp[i] += dp[i-1];
            }
        }
        
        return accumulate(dp.begin(), dp.end(), 0LL);
    }
};