class Solution(object):
    def minEatingSpeed(self, piles, h):
        """
        :type piles: List[int]
        :type h: int
        :rtype: int
        """
        left, right = 1, max(piles)
        
        def checkOK(target):
            tot = 0
            for pile in piles:
                tot += pile//target + (pile%target!=0)
            return tot <= h
        
        
        while left + 1 < right:
            mid = left + (right-left)//2
            if checkOK(mid):
                right = mid
            else:
                left = mid
        
        if checkOK(left):
            return left
        else:
            return right