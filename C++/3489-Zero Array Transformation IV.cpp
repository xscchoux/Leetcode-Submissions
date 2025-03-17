// First AC, knapsack, not efficient
class Solution {
public:
    bool isOK(vector<int>& nums, vector<vector<int>>& queries, int cnt) {
        int N = nums.size();
        vector<vector<int>> pos(N);
        for (int i=0; i<cnt; i++) {
            auto &q = queries[i];
            int u = q[0], v = q[1], w = q[2];
            for (int idx = u; idx <= v; idx++) {
                pos[idx].push_back(w);
            }
        }
        for (int i=0; i<nums.size(); i++) {
            // knapsack
            vector<bool> dp(nums[i]+1, false);
            dp[0] = true;
            for (int num:pos[i]) {
                for (int val = nums[i]; val > 0; val--) {
                    if (val - num < 0) break;
                    if (dp[val-num]) dp[val] = true;
                }
            }
            if (!dp[nums[i]]) return false;
        }

        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int N = nums.size();
        if (count(begin(nums), end(nums), 0) == N) return 0;

        int left = 1, right = queries.size();
        while (left + 1 < right) {
            int mid = left + (right-left)/2;
            if (isOK(nums, queries, mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }

        if (isOK(nums, queries, left)) {
            return left;
        } else if (isOK(nums, queries, right)) {
            return right;
        } else {
            return -1;
        }
    }
};



// Much better, use bitset, clever
class Solution {
public:
    int helper(int pos, vector<vector<int>> queries, int num) {
        if (!num) return 0; // if current number is zero
        bitset<1001> dp;
        dp[0] = 1;
        for (int i=0; i<queries.size(); i++) {
            int l = queries[i][0], r = queries[i][1], val = queries[i][2];
            if (l <= pos && pos <= r) {
                dp = dp | (dp<<val);
            }
            if (dp[num]) return i+1;
        }
        return INT_MAX;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int res = -1;
        for (int i=0; auto &n: nums) {
            res = max(res, helper(i++, queries, n));
        }

        return res == INT_MAX?-1:res;
    }
};