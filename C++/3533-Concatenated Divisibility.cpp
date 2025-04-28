class Solution {
public:
    int N, k, full;
    int dfs(int bitmask, int remainder, vector<int>& nums, vector<vector<int>>& dp) {
        if (bitmask == full) {
            if (remainder == 0) {
                dp[bitmask][remainder] = true;  // so we can get value in getRes()
                return true;
            }
            return false;
        }

        if (dp[bitmask][remainder] != -1) return dp[bitmask][remainder];

        bool res = false;
        for (int i=0; i<N; i++) {
            if ((bitmask >> i) & 1) continue;
            int digitLen = (int)log10(nums[i]) + 1;
            int newRemainder = (remainder*(int)pow(10, digitLen) + nums[i])%k;
            res |= dfs(bitmask^(1<<i), newRemainder, nums, dp);
        }

        return dp[bitmask][remainder] = res;
    }

    void getRes(int idx, int bitmask, int remainder, vector<int>& res, vector<int>& nums, vector<vector<int>>& dp) {
        if (idx == N) return;
        int currIdx = 0, currRemainder = 0;
        for (int i=0; i<N; i++) {
            if ((bitmask >> i) & 1) continue;
            int digitLen = (int)log10(nums[i]) + 1;
            int newRemainder = (remainder*(int)pow(10, digitLen) + nums[i])%k;
            if (dp[bitmask^(1<<i)][newRemainder] == 1 && nums[i] < res[idx]) {
                res[idx] = nums[i];
                currIdx = i;
                currRemainder = newRemainder;
            }            
        }

        if(res[idx] == INT_MAX) return;
        getRes(idx+1, bitmask^(1<<currIdx), currRemainder, res, nums, dp);
    }


    vector<int> concatenatedDivisibility(vector<int>& nums, int k) {
        N = nums.size();
        this->k = k;
        full = (1<<N)-1;
        vector<vector<int>> dp(1<<N, vector<int>(k, -1));

        bool hasRes = dfs(0, 0, nums, dp);
        if (!hasRes) return {};

        vector<int> res(N, INT_MAX);
        getRes(0, 0, 0, res, nums, dp);

        return res;
    }
};