class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int idx = lower_bound(begin(nums), end(nums), target) - begin(nums);

        if (idx + nums.size()/2 < nums.size() && nums[idx + nums.size()/2] == target) {
            return true;
        }
        return false;
    }
};