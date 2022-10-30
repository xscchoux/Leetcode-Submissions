class Solution(object):
    def makeIntegerBeautiful(self, n, target):
        """
        :type n: int
        :type target: int
        :rtype: int
        """
        def dfs(n):
            tot = sum([int(c) for c in str(n)])
            if tot <= target:
                return 0
            else:
                return 10 - n%10 + 10*dfs(n//10 + 1)
            
        return dfs(n)