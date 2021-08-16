class Solution(object):
    def findMaxConsecutiveOnes(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
# O(n)
        left = 0
        numZero = 0
        res = 0
        for i in range(len(nums)):
            if nums[i] == 0:
                numZero += 1
            if numZero == 2:
                res = max(res, i-1-left+1)
                while numZero == 2:
                    numZero -= 1-nums[left]
                    left += 1
        res = max(res, len(nums)-1-left+1)
        return res