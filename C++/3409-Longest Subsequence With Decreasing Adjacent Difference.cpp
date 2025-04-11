// First AC
class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int N = nums.size();
        unordered_map<int, int> lastPos;  // number : last index
        vector<vector<int>> dp(N, vector<int>(300, 1));
        int res = 1;

        for (int i=0; i<N; i++) {
            vector<int> diff2Val(300, 1);
            int val = 1, curr = 1;
            for (int diff=(300-nums[i]); diff>=0; diff--) {
                int prev = nums[i] + diff;
                if (lastPos.contains(prev)) {
                    val = max(val, 1 + dp[lastPos[prev]][diff]);
                }
                diff2Val[diff] = max(diff2Val[diff], val);
                dp[i][diff] = diff2Val[diff];
                curr = max(dp[i][diff], curr);
            }

            int val2 = 1;
            for (int diff=nums[i]-1; diff>=0; diff--) {
                int prev = nums[i] - diff;
                if (lastPos.contains(prev)) {
                    val2 = max(val2, 1 + dp[lastPos[prev]][diff]);
                }
                diff2Val[diff] = max(diff2Val[diff], val2);
                dp[i][diff] = diff2Val[diff];
                curr = max(dp[i][diff], curr);
            }

            res = max(res, curr);

            lastPos[nums[i]] = i;
        }

        return res;
    }
};


// Refactored
class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int N = nums.size();
        vector<int> lastPos(301, -1);
        vector<vector<int>> dp(N, vector<int>(300, 1));
        int res = 1;

        for (int i=0; i<N; i++) {
            int curr = 1;
            for (int diff=299; diff>=0; diff--) {
                if (nums[i] + diff <= 300) {
                    int prev = nums[i] + diff;
                    if (lastPos[prev] != -1) {
                        curr = max(curr, 1 + dp[lastPos[prev]][diff]);
                    }
                }
                if (nums[i] - diff >= 0) {
                    int prev = nums[i] - diff;
                    if (lastPos[prev] != -1) {
                        curr = max(curr, 1 + dp[lastPos[prev]][diff]);
                    }
                }
                dp[i][diff] = curr;
                res = max(res, curr);
            }
            lastPos[nums[i]] = i;
        }

        return res;
    }
};