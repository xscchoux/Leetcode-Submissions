class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int res = 0, left = 0;

        for (int i=0; i<nums.size(); i++) {
            while((long long)nums[left]*k < (long long)nums[i]) {
                left++;
            }
            res = max(res, i-left+1);
        }
        return nums.size()-res;
    }
};