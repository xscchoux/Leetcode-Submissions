class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int N = nums.size();

        vector<vector<int>> dp(N, vector<int>(k, 1));  // every nums[i] can be a starting number of a subsequence with (sub[i] + sub[i])%k = (value from 0~k-1)
        
        int res = 0;

        for (int i=1; i<N; i++) {
            for (int j=0; j<i; j++) {
                int remainder = (nums[i] + nums[j])%k;
                dp[i][remainder] = max(dp[i][remainder], dp[j][remainder] + 1);
                res = max(res, dp[i][remainder]);
            }
        }

        return res;
    }
};