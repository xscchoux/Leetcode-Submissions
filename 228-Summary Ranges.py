class Solution(object):
    def summaryRanges(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        if not nums:
            return []
        
        start, end = 0, 0
        
        res = []
        
        while start < len(nums):
            while end < len(nums)-1 and nums[end+1] == nums[end] + 1:
                end += 1
            if start== end:
                res.append(str(nums[start]))
            else:
                res.append( str(nums[start]) + "->" + str(nums[end]) )
                
            start, end = end+1, end+1
            
        return res