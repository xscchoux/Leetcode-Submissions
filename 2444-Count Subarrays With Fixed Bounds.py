class Solution(object):
    def countSubarrays(self, nums, minK, maxK):
        """
        :type nums: List[int]
        :type minK: int
        :type maxK: int
        :rtype: int
        """
        left = -1
        minPos = maxPos = -1
        res = 0
        
        for r in range(len(nums)):
            if nums[r] < minK or nums[r] > maxK:
                left = r
                minPos = -1
                maxPos = -1 
                continue
            if nums[r] == minK:
                minPos = r
            if nums[r] == maxK:
                maxPos = r
            if minPos != -1 and maxPos != -1:
                res += min(minPos, maxPos) - left
        
        return res