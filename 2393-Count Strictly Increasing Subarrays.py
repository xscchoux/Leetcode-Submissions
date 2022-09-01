class Solution(object):
    def countSubarrays(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        res = 0
        pre = 100001
        count = 1
        
        for num in nums:
            if num > pre:
                count += 1
            else:
                count = 1
            pre = num
            res += count
        
        return res