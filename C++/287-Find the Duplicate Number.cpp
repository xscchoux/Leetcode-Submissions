class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int num:nums) {
            if (nums[abs(num)-1] < 0) return abs(num);
            nums[abs(num)-1] *= -1;
        }
        return 0;
    }
};