class Solution:
    def minDays(self, n: int) -> int:
        
        @cache
        def dfs(remain):
            if remain <=2:
                return remain
            return 1 + min(remain%2 + dfs(remain//2), remain%3 + dfs(remain//3))
        
        return dfs(n)