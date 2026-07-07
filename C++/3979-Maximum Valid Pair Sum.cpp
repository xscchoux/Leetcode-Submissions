class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int N = nums.size();
        int mx = 0, res = 0;
        for (int i = N-1; i>=k; i--) {
            mx = max(nums[i], mx);
            res = max(res, mx + nums[i-k]);
        }

        return res;
    }
};