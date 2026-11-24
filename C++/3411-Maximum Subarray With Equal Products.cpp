class Solution {
public:
    int maxLength(vector<int>& nums) {
        // for an array of length 2, the identity prod(arr) == lcm(arr) * gcd(arr) always holds
        int N = nums.size(), res = 2;


        // for array length >= 3, the same prime factor can occur in at most one element
        // check here: https://leetcode.cn/problems/maximum-subarray-with-equal-products/solutions/3039079/mei-ju-ti-qian-tui-chu-xun-huan-pythonja-a21k/

        int left = 0, prod = 1;
        for (int i=0; i<N; i++) {
            while (__gcd(prod, nums[i]) > 1) {
                prod /= nums[left++];
            }
            prod *= nums[i];
            res = max(res, i-left+1);
        }

        return res;
    }
};