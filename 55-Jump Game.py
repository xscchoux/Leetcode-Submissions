# https://www.youtube.com/watch?v=yHU3nrww_ZA
class Solution(object):
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
# O(n)
        if not nums or len(nums) <= 1:
            return True
        lastpos = len(nums) - 1
        for i in range(len(nums)-1, -1, -1):
            if i + nums[i] >= lastpos:
                lastpos = i

        return lastpos == 0
    
# method 2
        _max = 0
        for i in range(len(nums)):
            if i > _max:
                return False
            _max = max(_max, i + nums[i])
            
        return True