class Solution(object):
    def findKthNumber(self, m, n, k):
        """
        :type m: int
        :type n: int
        :type k: int
        :rtype: int
        """
# O(m*log(m*n))

        def isEnough(val):
            count = 0
            for i in range(1, m+1):
                count += min(val//i, n)
            
            return count >= k
        
        left, right = 1, m*n
        
        while left + 1 < right:
            mid = left + (right-left)//2
            if isEnough(mid):
                right = mid
            else:
                left = mid
                
        if isEnough(left):
            return left
        else:
            return right