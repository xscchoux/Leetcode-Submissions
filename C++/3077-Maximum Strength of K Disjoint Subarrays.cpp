using LL = long long;
class Solution {
public:
    LL dfs(int idx, int remain, bool hasElement, vector<int>& nums, vector<vector<vector<LL>>>& dp) {
        if (remain == 0) return 0;
        if (idx==nums.size()) {
            if (remain == 1 && hasElement) return 0;
            else return -1e15;
        }
        
        if (dp[idx][remain][hasElement] != -1e16) return dp[idx][remain][hasElement];
        
        LL res = -1e15;
        // if there's element
        if (hasElement) {
            // start a new subarray
            res = max(res, (LL)((remain-1)%2 == 1? 1:-1)*(remain-1)*nums[idx] + dfs(idx+1, remain-1, true, nums, dp));
            // append a new element in current subarray
            res = max(res, (LL)(remain%2 == 1? 1:-1)*remain*nums[idx] + dfs(idx+1, remain, true, nums, dp));
            // skip current element, get ready for next subarray, so remain - 1
            res = max(res, dfs(idx+1, remain-1, false, nums, dp));
        } else {
            // start a new subarray
            res = max(res,  (LL)(remain%2 == 1? 1:-1)*remain*nums[idx] + dfs(idx+1, remain, true, nums, dp));
            // skip current element
            res = max(res, dfs(idx+1, remain, false, nums, dp));            
        }
        return dp[idx][remain][hasElement] = res;
    }
    
    long long maximumStrength(vector<int>& nums, int k) {
        int N = nums.size();
        vector<vector<vector<LL>>> dp(N+1, vector<vector<LL>>(k+1, vector<LL>(2, -1e16)));
        return dfs(0, k, false, nums, dp);
    }
};