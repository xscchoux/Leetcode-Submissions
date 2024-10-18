// O(N*(max OR value))
class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int mx = 0, N = nums.size();
        vector<int> dp(1<<17);
        dp[0] = 1;

        for (int num:nums) {
            for (int val=mx; val>=0; val--) {
                dp[val|num] += dp[val];
            }
            mx |= num;
        }

        return dp[mx];
    }
};



// fastest clever solution
class Solution {
public:
    int N, count;
    void dfs(vector<int>& nums, int val, int idx, int target) {
        if (val == target) {
            count += 1<<(N-idx);
            return;
        }

        if (idx == N) return;

        dfs(nums, val|nums[idx], idx+1, target);
        dfs(nums, val, idx+1, target);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int target = 0;
        N = nums.size();
        for (int num:nums) target |= num;
        dfs(nums, 0, 0, target);

        return count;
    }
};