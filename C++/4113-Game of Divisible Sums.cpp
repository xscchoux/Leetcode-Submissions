class Solution {
public:
    int N;
    long long dp[100001][2];
    long long dfs(vector<int>& nums, int idx, int turn) {
        if (idx == N) {
            return 0;
        }

        if (dp[idx][turn] != -1) {
            return dp[idx][turn];
        }

        long long res = LLONG_MIN;
        // take one
        int val = nums[idx];
        if (val%3 == 0) res = max(res, val - dfs(nums, idx+1, 1-turn));
        else res = max(res, val + dfs(nums, idx+1, turn));

        // take two
        if (idx + 1 < N) {
            int val2 = nums[idx] + nums[idx+1];
            if (val2%3 == 0) res = max(res, val2 - dfs(nums, idx+2, 1-turn));
            else res = max(res, val2 + dfs(nums, idx+2, turn));
        }

        return dp[idx][turn] = res;
    }
    long long maxDifference(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        this->N = nums.size();

        return dfs(nums, 0, 0);
    }
};