class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0, left = 0, right = nums.size()-1;
        while (left < right){
            res = max(res, nums[right] + nums[left]);
            right--;left++;
        }
        return res;
    }
};