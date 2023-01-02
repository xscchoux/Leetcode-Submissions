class Solution(object):
    def isIdealPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        
        N = len(nums)
        preMin = float('inf')
        
        for i in range(N-1, -1, -1):
            preMin = min(preMin, nums[i])
            if i >= 2 and nums[i-2] > preMin:
                return False
        return True