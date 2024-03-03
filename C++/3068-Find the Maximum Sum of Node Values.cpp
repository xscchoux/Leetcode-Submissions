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