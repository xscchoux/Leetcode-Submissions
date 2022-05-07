class Solution(object):
    def longestSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
# sliding window
        curr = 0
        left = 0
        res = 0
        zeros = 0

        for i in range(len(nums)):
            curr += nums[i]
            if nums[i] == 0:
                while i > left and curr < i - left:
                    curr -= nums[left]
                    left += 1
            res = max(res, i-left)
        return res
    
# two subarrays

        prev = curr = 0
        res = 0
        
        for i in range(len(nums)):
            if nums[i] == 1:
                curr += 1
            else:
                res = max(res, curr+prev)
                prev = curr
                curr = 0
                
        res = max(curr+prev, res)
        
        if curr == len(nums):
            return curr-1
        
        return res
                
        