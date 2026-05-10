class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int N = nums.size();

        vector<int> dp(N, -1);
        dp[0] = 0;

        for (int i=1; i<N; i++) {
            for (int j=0; j<i; j++) {
                if (abs(nums[i]-nums[j]) <= target && dp[j] != -1) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return dp[N-1];
    }
};


// use short
class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int N = nums.size();

        vector<short> dp(N, -1);
        dp[0] = 0;

        for (int i=1; i<N; i++) {
            for (int j=0; j<i; j++) {
                if (abs(nums[i]-nums[j]) <= target && dp[j] != -1) {
                    dp[i] = max(dp[i], (short)(dp[j] + 1));
                }
            }
        }

        return dp[N-1];
    }
};