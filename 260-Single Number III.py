class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        bitmask = 0
        for num in nums:
            bitmask = bitmask^num
            
        diff = bitmask&(-bitmask)
        
        x = 0
        for num in nums:
            if diff & num:
                x = x^num
        
        return [x, bitmask^x]