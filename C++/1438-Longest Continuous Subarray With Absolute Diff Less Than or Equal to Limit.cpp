class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int res = 0, N = nums.size(), left = 0;
        multiset<int> mul;

        for (int i=0; i<N; i++) {
            mul.insert(nums[i]);
            while (*prev(mul.end()) - *mul.begin() > limit) {
                mul.erase(mul.find(nums[left]));  // it will remove only one value of nums[left], mul.erase(nums[left]) will remove all instance of value nums[left]
                left++;
            }
            res = max(res, i-left+1);
        }
        return res;
    }
};