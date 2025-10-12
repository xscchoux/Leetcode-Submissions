class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0, N = nums.size(), res = 0;

        for (int i=0; i<N; i++) {
            while (i-left+1 >= 3 && nums[i] != (nums[i-1] + nums[i-2])) {
                left++;
            }
            res = max(res, i-left+1);
        }

        return res;
    }
};