class Solution(object):
    def getMaxLen(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        res = 0
        pos = neg = 0
        for num in nums:
            if num == 0:
                pos = neg = 0
            elif num > 0:
                pos, neg = pos+1, neg+1 if neg else 0
            else:
                pos, neg = neg + 1 if neg else 0, pos + 1
            res = max(pos, res)
        
        return res