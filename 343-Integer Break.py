class Solution(object):
    def integerBreak(self, n):
        """
        :type n: int
        :rtype: int
        """
        memo = {2:1, 3:2, 4:4, 5:6, 6:9}
        
        def breaker(n):
            if n in memo:
                return memo[n]
            return 3*breaker(n-3)
        
        return breaker(n)