class Solution(object):
    def maxAreaOfIsland(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        
        row = len(grid)
        col = len(grid[0])
        
        def dfs(r, c):
            grid[r][c] = 0
            tot = 1
            for dr, dc in ((1,0),(0,1),(-1,0),(0,-1)):
                newR = r + dr
                newC = c + dc
                if 0 <= newR < row and 0 <= newC < col and grid[newR][newC] == 1:
                    tot += dfs(newR, newC)
            return tot
        
        res = 0
        
        for r in range(row):
            for c in range(col):
                if grid[r][c] == 1:
                    res = max(res, dfs(r, c))
        return res