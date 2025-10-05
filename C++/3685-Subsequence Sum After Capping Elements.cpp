class Solution {
public:
    vector<bool> subsequenceSumAfterCapping(vector<int>& nums, int k) {
        int N = nums.size();
        sort(begin(nums), end(nums));

        vector<bool> res(N, false), dp(k+1, false);
        dp[0] = true;

        int idx = 0;

        for (int x=1; x<=N; x++) {
            // Knapsack DP for unchanged nums[i]
            while (idx<N && nums[idx] <= x) {
                for (int kk = k; kk >= nums[idx]; kk--) {
                    if (dp[kk-nums[idx]]) {
                        dp[kk] = true;
                    }
                }
                idx++;
            }
            
            // for those with replaced value
            int replaceCnt = N-idx;
            for (int cnt=0; cnt <= replaceCnt && cnt*x <= k; cnt++) {
                if (dp[k - cnt*x]) {
                    res[x-1] = true;
                    break;
                }
            }

        }

        return res;
    }
};