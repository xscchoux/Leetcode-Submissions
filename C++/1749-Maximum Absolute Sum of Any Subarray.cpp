class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int N = nums.size(), res = 0;
        int currMin = 0, currMax = 0;

        for (int num:nums) {
            if (currMax + num < 0) {
                currMax = 0;
            } else {
                currMax += num;
                res = max(currMax, res);
            }

            if (currMin + num > 0) {
                currMin = 0;
            } else {
                currMin += num;
                res = max(-currMin, res);
            }
        }

        return res;
    }
};