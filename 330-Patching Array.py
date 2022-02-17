class Solution(object):
    def minPatches(self, nums, n):
        """
        :type nums: List[int]
        :type n: int
        :rtype: int
        """
        reachable = 0
        res = 0
        idx = 0
        
        while reachable < n:
            if idx < len(nums) and nums[idx] <= reachable+1:
                reachable += nums[idx]
                idx += 1
            else:
                res += 1
                reachable += (reachable+1)
        
        return res