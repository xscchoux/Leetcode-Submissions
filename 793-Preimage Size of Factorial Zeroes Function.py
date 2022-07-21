class Solution(object):
    def preimageSizeFZF(self, k):
        """
        :type k: int
        :rtype: int
        """
        def countZero(x):
            if x == 0:
                return 0
            return x//5 + countZero(x//5)
        
# therefore, if x is the largest integer such that x! has no more than K trailing zeros, then we have x <= 5 * (K + 1), which can serve as the upper bound of our binary search.

        left, right = 0, 5*(k+1)
        
        while left + 1 < right:
            mid = left + (right-left)//2
            if countZero(mid) <= k:
                left = mid
            else:
                right = mid
                
        if countZero(left) == k:
            return 5
        else:
            return 0