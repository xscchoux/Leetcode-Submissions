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


class Solution:
    def integerBreak(self, n: int) -> int:
        if n == 2 or n == 3:
            return n - 1
        
        @cache
        def dfs(val):
            if val <= 3:
                return val
            res = val
            for i in range(2, val):
                res = max(res, i*dfs(val-i))
            return res
            
        return dfs(n)