class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(begin(nums), end(nums));
        for (int i=nums.size()-1; i>=2; i--) {
            if (nums[i-2] + nums[i-1] > nums[i]) {
                return nums[i] + nums[i-1] + nums[i-2];
            }
        }

        return 0;
    }
};