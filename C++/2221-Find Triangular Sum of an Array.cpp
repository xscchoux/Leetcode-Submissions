class Solution {
public:
    int triangularSum(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];

        while (nums.size() > 1) {
            int sz = nums.size();
            for (int i=0; i<sz-1; i++) {
                nums[i] = (nums[i] + nums[i+1])%10;
            }
            nums.pop_back();
        }

        return nums[0];
    }
};