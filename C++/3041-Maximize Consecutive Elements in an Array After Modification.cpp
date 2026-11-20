class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        int N = nums.size();
        sort(begin(nums), end(nums));

        int res = 1;
        unordered_map<int, int> dp;
        dp[nums[0]] = 1;
        dp[nums[0]+1] = 1;


        for (int i=1; i<N; i++) {
            dp[nums[i]+1] = max(dp[nums[i]+1], dp[nums[i]]+1);
            res = max(res, dp[nums[i]+1]);

            dp[nums[i]] = max(dp[nums[i]], dp[nums[i]-1] + 1);
            res = max(res, dp[nums[i]]);
        }

        return res;
    }
};