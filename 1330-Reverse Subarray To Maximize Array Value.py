class Solution:
    def maxValueAfterReverse(self, nums: List[int]) -> int:
# https://leetcode.com/problems/reverse-subarray-to-maximize-array-value/discuss/489882/O(n)-Solution-with-explanation 
        mx, mn = -float('inf'), float('inf')
        change = 0
        for a, b in zip(nums, nums[1:]):
            mx = max(min(a, b), mx)
            mn = min(max(a, b), mn)
            change = max(change, 2*(mx-mn))
        
        for a, b in zip(nums, nums[1:]):
            tmp1 = -abs(a-b) + abs(nums[0] - b)
            tmp2 = -abs(a-b) + abs(a - nums[-1])
            change = max(change, tmp1, tmp2)
        
        tot = sum(abs(a-b) for a, b in zip(nums, nums[1:]))
        
        return tot + change