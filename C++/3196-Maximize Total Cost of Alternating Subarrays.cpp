class Solution {
public:
    int N;
    long long dfs(vector<int>& nums, int ind, vector<long long> &memo) {
        if (ind == N) return 0;
        if (memo[ind] != -1) return memo[ind];

        long long tot = 0;
        // + + ....
        tot = nums[ind] + dfs(nums, ind+1, memo);
        // + - ....
        if (ind + 1 <= N-1) {
            tot = max(tot, nums[ind] - nums[ind+1] + dfs(nums, ind+2, memo));
        }
        
        return memo[ind] = tot;
    }
    long long maximumTotalCost(vector<int>& nums) {
        this->N = nums.size();
        vector<long long> memo(N, -1);
        dfs(nums, 0, memo);
        return memo[0];
    }
};