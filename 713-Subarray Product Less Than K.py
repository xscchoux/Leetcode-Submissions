class Solution(object):
    def numSubarrayProductLessThanK(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
# sliding window

        # optional
        if k<=1:
            return 0
    
        val = 1
        left = 0
        res = 0
        
        for i in range(len(nums)):
            val *= nums[i]
            while left <= i and val >= k:
                val //= nums[left]
                left+=1
            res += i - left + 1
            
        return res