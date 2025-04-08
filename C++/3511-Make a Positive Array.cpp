// https://leetcode.com/problems/make-a-positive-array/solutions/6627037/python3-one-pass-greedy-o-n-time-and-o-1-space/
using LL = long long;
class Solution {
public:
    int makeArrayPositive(vector<int>& nums) {
        int op = 0, N = nums.size();
        vector<LL> convertedNums(begin(nums), end(nums));
        LL preMin = 0;

        for (int i=0; i<2; i++) {
            preMin += convertedNums[i];
        }

        for (int i=2; i<N; i++) {
            preMin = min(preMin + convertedNums[i], convertedNums[i] + convertedNums[i-1] + convertedNums[i-2]);
            if (preMin <= 0) {
                convertedNums[i] = 1e18;
                preMin = 1e18;   // preMin may be smaller than 1e18, but this doesn't matter because -1e9 <= nums[i] <= 1e9
                op++;
            }
        }

        return op;
    }
};