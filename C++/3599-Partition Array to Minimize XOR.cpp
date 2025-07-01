class Solution {
public:
    int minXor(vector<int>& nums, int k) {
        int N = nums.size();
        vector<vector<int>> dp(N, vector<int>(k+1, INT_MAX));
        // let dp[i][k] be the answer for splitting nums[:i] into k subarrays
        // dp[i][k] : minimum possible value of the maximum XOR among these k subarrays

        for (int i=0; i<N; i++) {
            int curr = 0;
            for (int j=i; j>=0; j--) {
                curr = curr^nums[j];
                if (j == 0) {
                    dp[i][1] = curr;
                } else {
                    for (int kk=1; kk<min(k, j+1); kk++) {
                        dp[i][kk+1] = min(dp[i][kk+1], max(dp[j-1][kk], curr));
                    }
                }
            }
        }

        return dp[N-1][k];
    }
};