class Solution:
    def integerReplacement(self, n: int) -> int:
        @cache
        def dfs(curr):
            if curr == 1:
                return 0
            
            if curr%2 == 1:
                return min(1 + dfs(curr-1), 1 + dfs(curr+1))
            else:
                return 1 + dfs(curr//2)
            
        return dfs(n)