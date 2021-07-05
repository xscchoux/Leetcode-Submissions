class Solution(object):
    def numTrees(self, n):
        """
        :type n: int
        :rtype: int
        """
        memo = dict()
        
        def dfs(n):
            if n <= 1:
                return 1
            if n in memo:
                return memo[n]
            res = 0
            for i in range(n):
                res += dfs(i)*dfs(n-i-1)
            memo[n] = res
            return res
        
        return dfs(n)