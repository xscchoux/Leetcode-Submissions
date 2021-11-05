class Solution(object):
    def minDifference(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        N = len(nums)
        if N <= 4:
            return 0
        
        res = float('inf')
        
        nums.sort()

        for i in range(4):
            res = min(res, nums[N-4+i]-nums[i])
        
        return res