class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int N = nums.size(), res = 0;

        for (int i=N-1; i>=2; i--) {
            int left = 0, right = i-1;
            while (left < right) {
                if (nums[left] + nums[right] > nums[i]) {
                    res += right-left;
                    right--;
                } else {
                    left++;
                }
            }
        }

        return res;
    }
};