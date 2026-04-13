class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int res = 0;
        for (int num:nums) {
            while (num > 0) {
                if (num%10 == digit) {
                    res++;
                }
                num = num/10;
            }
        }

        return res;
    }
};