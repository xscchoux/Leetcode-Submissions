class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int N = nums.size();
        vector<vector<int>> dp(N, vector<int>(1001, 1));
        int res = 0;
        for (int i=0; i<N; i++) {
            for (int j=0; j<i; j++) {
                int diff = 500 + nums[i]-nums[j];
                dp[i][diff] = dp[j][diff] + 1;
                res = max(res, dp[i][diff]);
            }
        }
        return res;
    }
};