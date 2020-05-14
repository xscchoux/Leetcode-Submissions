class Solution(object):
    def jump(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
# O(n)
# https://www.youtube.com/watch?v=vBdo7wtwlXs
        steps = 0
        lastReach = 0
        curReach = 0
        for i in range(len(nums)):
            if i>lastReach:
                steps += 1
                lastReach = curReach
            curReach = max(curReach, i+nums[i])
            
        return steps