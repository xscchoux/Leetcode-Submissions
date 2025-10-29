class Solution {
public:
    int dp[1001];
    int N;
    int dfs(int startIdx, vector<int>& nums) {
        if (startIdx == N) return 0;
        if (dp[startIdx] != -1) {
            return dp[startIdx];
        }

        int res = INT_MAX/2;
        for (int i=startIdx; i<N; i++) {
            if (__gcd(nums[i], nums[startIdx]) > 1) {
                res = min(res, 1+dfs(i+1, nums));
            }
        }

        return dp[startIdx] = res;
    }

    int validSubarraySplit(vector<int>& nums) {
        if (nums.front() == 1 || nums.back() == 1) return -1;
        this->N = nums.size();
        memset(dp, -1, sizeof(dp));

        int res = dfs(0, nums);
        return res==INT_MAX/2?-1:res;
    }
};