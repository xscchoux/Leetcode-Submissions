class Solution(object):
    def longestOnes(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
# My solution
        left = 0
        res = 0
        
        for i in range(len(nums)):
            k -= 1 - nums[i]
            while k < 0:
                res = max(res, i - left)
                k += 1 - nums[left]
                left += 1

        res = max(res, len(nums)-left)
        return res
    
# better sliding window
        left = 0
        for right in range(len(nums)):
            k -= 1- nums[right]
            if k < 0:
                k += 1-nums[left]
                left += 1
                
        return right - left + 1