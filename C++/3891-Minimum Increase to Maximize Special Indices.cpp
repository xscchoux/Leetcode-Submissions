class Solution {
public:
    int N;
    long long dfs(int idx, int skip, vector<int>& nums, vector<vector<long long>>& dp) {
        if (idx >= N-1) {
            return 0;
        }

        if (dp[skip][idx] != -1) return dp[skip][idx];
        
        long long res = max(0, max(nums[idx-1], nums[idx+1]) + 1 - nums[idx]);
        
        if (skip) {
            res += dfs(idx+2, skip, nums, dp);
        } else {
            // skip or no skip
            res += min(dfs(idx+3, true, nums, dp), dfs(idx+2, false, nums, dp));
        }

        return dp[skip][idx] = res;
    }
    long long minIncrease(vector<int>& nums) {
        this->N = nums.size();
        if (N%2) {
            long long res = 0;
            for (int i=1; i<N; i+=2) {
                res += max(0, max(nums[i-1], nums[i+1]) + 1 - nums[i]);
            }
            return res;
        } else {
            // we choose skip at most once in this case
            vector<vector<long long>> dp(2, vector<long long>(N, -1));   // dp[skipped/not skipped][index]:operation

            return min(dfs(1, false, nums, dp), dfs(2, true, nums, dp));
        }
    }
};