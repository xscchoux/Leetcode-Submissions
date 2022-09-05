class Solution(object):
    def longestNiceSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        res = 0
        left = 0
        running = 0
        
        for i, num in enumerate(nums):
            while running & num != 0:
                running = running^nums[left]
                left += 1
            running = running | num
            res = max(res, i-left+1)
        return res