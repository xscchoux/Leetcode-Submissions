class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        for (int num:nums) {
            k = k^num;
        }
        return __builtin_popcount(k);
    }
};