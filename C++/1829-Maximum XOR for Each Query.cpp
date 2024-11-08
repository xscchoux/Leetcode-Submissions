// Unintentionally neglected 0 <= nums[i] < 2^maximumBit condition...
class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int mx = pow(2, maximumBit)-1;
        int res = 0;
        for (int num:nums) res ^= num;
        vector<int> arr;

        for (int i=nums.size()-1; i>=0; i--) {
            arr.push_back((res|mx)^res);
            res ^= nums[i];
        }

        return arr;
    }
};