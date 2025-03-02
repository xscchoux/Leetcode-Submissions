class Solution {
public:
    int N;
    int dfs(int idx, int notRemoved, vector<int>& nums, vector<vector<int>>& dp) {
        if (idx > N-1) return nums[notRemoved];
        else if (idx == N-1) return max(nums[N-1], nums[notRemoved]);

        if (dp[idx][notRemoved] != -1) return dp[idx][notRemoved];

        int res = max(nums[idx], nums[idx+1]) + dfs(idx+2, notRemoved, nums, dp);
        res = min(res, max(nums[notRemoved], nums[idx+1]) + dfs(idx+2, idx, nums, dp));
        res = min(res, max(nums[notRemoved], nums[idx]) + dfs(idx+2, idx+1, nums, dp));

        return dp[idx][notRemoved] = res;
    }

    int minCost(vector<int>& nums) {
        this->N = nums.size();
        if (N <= 2) {
            return *max_element(begin(nums), end(nums));
        }
        vector<vector<int>> dp(N+1, vector<int>(N+1, -1));
        
        return dfs(1, 0, nums, dp);
    }
};