class Solution:
    def lastRemaining(self, n: int) -> int:
        
        def dfs(n, fromLeft):
            if n == 1:
                return 1
            if fromLeft:
                return 2*dfs(n//2, not fromLeft)
            elif n%2 == 0:
                return 2*dfs(n//2, not fromLeft) - 1
            else:
                return 2*dfs(n//2, not fromLeft)
        
        return dfs(n, True)