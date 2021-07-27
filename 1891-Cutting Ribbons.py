class Solution(object):
    def maxLength(self, ribbons, k):
        """
        :type ribbons: List[int]
        :type k: int
        :rtype: int
        """
        def count(val):
            res = 0
            for ribbon in ribbons:
                res += ribbon//val
            return res
        
        total = _max = 0
        for ribbon in ribbons:
            total += ribbon
            _max = max(_max, ribbon)
        
        if k > total:
            return 0
        
        left, right = 1, min(total // k, _max)
        
        while left +1 < right:
            mid = left + (right-left)//2
            if count(mid) >= k:
                left = mid
            else:
                right = mid
        
        if count(right) >= k:
            return right
        elif count(left) >= k:
            return left
        else:
            return 0