class Solution {
public:
    void sortColors(vector<int>& nums) {
        int N = nums.size();
        int i0 = 0, curr = 0, i2 = N-1;

        while (curr <= i2) {
            if (nums[curr] == 0) {
                swap(nums[i0++], nums[curr++]);
            } else if (nums[curr] == 2) {
                swap(nums[curr], nums[i2--]);
            } else {
                curr++;
            }
        }
    }
};