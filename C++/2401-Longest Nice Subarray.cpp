class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int currBits = 0, left = 0, res = 1;
        for (int i=0; i<nums.size(); i++) {
            while ( (currBits & nums[i]) != 0) {
                currBits ^= nums[left];
                left++;
            }
            currBits |= nums[i];
            res = max(res, i-left+1);
        }

        return res;
    }
};