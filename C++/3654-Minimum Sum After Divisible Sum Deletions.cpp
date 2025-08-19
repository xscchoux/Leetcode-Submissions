class Solution {
public:
    long long minArraySum(vector<int>& nums, int k) {
        int N = nums.size(), curr = 0;
        unordered_map<int, int> modIdx;  // remainder to index
        modIdx[0] = N;
        vector<long long> dp(N+1, 0);

        for (int i=N-1; i>=0; i--) {
            curr = (curr + nums[i]%k)%k;
            dp[i] = nums[i] + dp[i+1];
            if (modIdx.contains(curr)) {
                dp[i] = min(dp[i], dp[modIdx[curr]]);
            }
            // Update earliest index for this remainder
            modIdx[curr] = i;
        }
        
        return dp[0];
    }
};