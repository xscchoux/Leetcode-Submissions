class Solution(object):
    def maxFrequency(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        nums.sort()
        
        res = 1
        left = 0
        toAdd = 0
        
        for i in range(1, len(nums)):
            toAdd += (nums[i] - nums[i-1])*(i - left)
            while toAdd > k:
                toAdd -= (nums[i]-nums[left])
                left += 1
            res = max(res, i-left+1)
            
        return res