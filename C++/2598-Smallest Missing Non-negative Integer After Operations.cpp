class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> cnt(value, 0);
        for (int num:nums) {
            cnt[(num%value+value)%value]++;
        }

        int res = 0;
        while (cnt[res%value]-- != 0) {
            res++;
        }

        return res;
    }
};