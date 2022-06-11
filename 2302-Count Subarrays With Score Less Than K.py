class Solution(object):
    def countSubarrays(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        res = 0
        left = 0
        
        running = 0
        for i in range(len(nums)):
            running += nums[i]
            while left <= i and running*(i-left+1) >= k:
                running = running - nums[left]
                left += 1
            res += (i-left+1)
            
        return res