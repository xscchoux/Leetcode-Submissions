class Solution {
public:
    vector<int> reverseSubarrays(vector<int>& nums, int k) {
        int N = nums.size(), len = N/k, idx = 0;
        
        while (idx < N) {
            reverse(begin(nums) + idx, begin(nums)+idx+len);
            idx += len;
        }

        return nums;
    }
};