# https://www.youtube.com/watch?v=yHU3nrww_ZA
class Solution(object):
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        if not nums or len(nums) <= 1:
            return True
        
        lastpos = len(nums) - 1
      
        for i in range(len(nums)-1, -1, -1):
            if i + nums[i] >= lastpos:
                lastpos = i

        return lastpos == 0