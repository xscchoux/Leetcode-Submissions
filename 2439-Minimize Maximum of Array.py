class Solution(object):
    def minimizeArrayValue(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        mx = 0
        curr = 0
        
        for i in range(len(nums)):
            curr += nums[i]
            mx = max(mx, (curr+i)//(i+1))
            
        return mx