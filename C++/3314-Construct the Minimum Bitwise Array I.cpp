class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> res;
        for (int &num:nums) {
            int ans = -1, d = 1;

            // Count 1s in the binary expression of from tail; remove the leading 1 in this successive 1's.
            while ((num&d)) {
                ans = num - d;
                d <<= 1;
            }
            num = ans;
        }
        return nums;
    }
};