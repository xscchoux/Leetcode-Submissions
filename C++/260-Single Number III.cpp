class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long bitmask = 0;
        for (int num:nums) {
            bitmask ^= num;
        }

        long diff = bitmask&(-bitmask);  // use long here because the negation of -2147483648 cannot be represented in type 'int'
        int x = 0;
        for (int num:nums) {
            if (num&diff) {
                x = x^num;
            }
        }
        
        return {x, (int)bitmask^x};
    }
};