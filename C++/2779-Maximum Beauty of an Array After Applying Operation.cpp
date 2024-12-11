class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int left = 0, N = nums.size(), res = 0;
        for (int i=0; i<N; i++) {
            if (nums[i]-nums[left] > 2*k) {
                left++;
            }
            res = max(res, i-left+1);
        }

        return res;
    }
};