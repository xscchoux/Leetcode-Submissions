// https://leetcode.com/problems/find-the-maximum-sum-of-node-values/discuss/4811566/JavaC%2B%2BPython-Edges-are-Useless
using LL = long long;
class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        LL res = 0;
        int update = 0;
        int diff = 1000000000;
        for (int num:nums) {
            int changed = num^k;
            if (changed > num) update++;
            res += max(changed, num);
            diff = min(diff, abs(changed-num));
        }
        return res - (update%2?diff:0);
    }
};



// Faster solution with one trick 
class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        // we can only change even number of nodes
        long long res = 0, minDiff = LLONG_MAX;
        int isOdd = 0;
        for (int i=0; i<nums.size(); i++) {
            int newNum = nums[i]^k;
            res += max(nums[i], newNum);
            if (newNum > nums[i]) {
                isOdd = 1 - isOdd;
            }
            minDiff = min(minDiff, (long long)abs(newNum - nums[i]));
            // if newNum - nums[i] is negative, and isOdd is 1, we change one node
            // if newNum - nums[i] is positive, and isOdd is 1, we revert the change of one node
        }

        return res - isOdd*minDiff;
    }
};