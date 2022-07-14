class Solution(object):
    def minimumSwaps(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        mn, mx = float('inf'), float('-inf')
        minInd, maxInd = len(nums)-1, 0
        
        for i, num in enumerate(nums):
            if num < mn:
                minInd = i
                mn = num
            if num >= mx:
                maxInd = i
                mx = num
        
        tot = minInd + len(nums)-1-maxInd
        
        if minInd > maxInd:
            return tot-1
        return tot