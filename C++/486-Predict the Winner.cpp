class Solution {
public:
    int N;
    int dfs(int start, int end, vector<int>& nums, vector<vector<int>>& dp) {
        if (start == end) {
            return nums[start];
        }
        if (dp[start][end] != -1) return dp[start][end];
        int res = max(nums[start] - dfs(start+1, end, nums, dp), nums[end] - dfs(start, end-1, nums, dp));

        return dp[start][end] = res;
    }

    bool predictTheWinner(vector<int>& nums) {
        this->N = nums.size();
        vector<vector<int>> dp(N, vector<int>(N, -1));
        int res = dfs(0, N-1, nums, dp);
        
        return res >= 0;
    }
};