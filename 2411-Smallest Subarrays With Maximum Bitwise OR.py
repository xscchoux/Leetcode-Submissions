class Solution(object):
    def smallestSubarrays(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        res = [1]*len(nums)
        count = [0]*31
        
        for i in range(len(nums)-1, -1, -1):
            for j in range(31):
                if nums[i] & (1 << j):
                    count[j] = i
            mx = max(1, max(count)-i+1)
            res[i] = mx
        
        return res