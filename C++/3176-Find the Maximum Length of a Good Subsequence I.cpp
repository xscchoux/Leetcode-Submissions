class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int N = nums.size();
        vector<vector<int>> dp(N, vector<int>(k+1, 1));
        int res = 1;

        for (int i=1; i<N; i++) {
            for (int j=0; j<i; j++) {
                if (nums[i] == nums[j]) {
                    for (int kk=0; kk<=k; kk++) {
                        dp[i][kk] = max(dp[i][kk], dp[j][kk] + 1);
                    }
                } else {
                    for (int kk=0; kk<k; kk++) {
                        dp[i][kk+1] = max(dp[i][kk+1], dp[j][kk] + 1);
                    }
                }
            }
            for (int kk=0; kk<=k; kk++) {
                res = max(res, dp[i][kk]);
            }
        }

        return res;
    }
};