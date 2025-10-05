class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int N = nums.size(), xorVal = 0, nonZero = 0;
        
        for (int num:nums) {
            if (num > 0) nonZero++;
            xorVal = xorVal^num;
        }

        if (xorVal > 0) return N;
        
        return nonZero > 0?N-1:0;
    }
};