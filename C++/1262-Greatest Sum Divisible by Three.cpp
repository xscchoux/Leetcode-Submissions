// First AC
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int N = nums.size();
        vector<vector<int>> dp(N, vector<int>(3, INT_MIN/2));
        dp[0][0] = 0;
        dp[0][(nums[0]%3)] = nums[0];

        for (int i=1; i<N; i++) {
            for (int j=0; j<3; j++) {
                dp[i][(j+nums[i])%3] = max(dp[i-1][(j+nums[i])%3], dp[i-1][j] + nums[i]);
            }
        }

        return dp.back()[0];
    }
};


// Better, O(1) space
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int N = nums.size();
        vector<int> dp = {0, INT_MIN, INT_MIN};

        for (int i=0; i<N; i++) {
            vector<int> tmp = dp;
            for (int j=0; j<3; j++) {
                tmp[(j+nums[i])%3] = max(dp[(j+nums[i])%3], dp[j] + nums[i]);
            }
            dp = move(tmp);
        }

        return dp[0];
    }
};


// Even better
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int N = nums.size();
        int dp[3] = {0, INT_MIN, INT_MIN};

        for (int i=0; i<N; i++) {
            int tmp[3] = {dp[0], dp[1], dp[2]};
            for (int j=0; j<3; j++) {
                tmp[(j+nums[i])%3] = max(dp[(j+nums[i])%3], dp[j] + nums[i]);
            }
            copy(tmp, tmp + 3, dp);
        }

        return dp[0];
    }
};