class Solution:
    def isPossibleToCutPath(self, grid: List[List[int]]) -> bool:
        m, n = len(grid), len(grid[0])
        
        def dfs(r, c):
            if r == m-1 and c == n-1:
                return True
            if grid[r][c] != 1:
                return False
            else:
                grid[r][c] = 0
            
            if r+1 < m and dfs(r+1, c):
                return True
            if c+1 < n and dfs(r, c+1):
                return True
            return False
        
        dfs(0, 0)
        grid[0][0] = 1
        return not dfs(0, 0)