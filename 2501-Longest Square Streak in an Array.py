class Solution(object):
    def longestSquareStreak(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        seen = dict()
        nums.sort(reverse = True)
        res = -1
        
        for num in nums:
            if num*num in seen:
                seen[num] = seen[num*num] + 1
                res = max(res, seen[num])
            else:
                seen[num] = 1
        
        return res