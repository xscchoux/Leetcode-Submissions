class Solution(object):
    def numEnclaves(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        row = len(grid)
        col = len(grid[0])
        
        def dfs(r, c):
            grid[r][c] = 0
            for dr, dc in ((1,0),(0,1),(-1,0),(0,-1)):
                newR = r+dr
                newC = c+dc
                if 0<=newR<row and 0<=newC<col and grid[newR][newC] == 1:
                    dfs(newR,newC)
        
        res = 0
        for r in (0, row-1):
            for c in range(col):
                if grid[r][c] == 1:
                    dfs(r,c)
                    
        for r in range(row):
            for c in (0, col-1):
                if grid[r][c] == 1:
                    dfs(r, c)
                    
        return sum([grid[r][c] for r in range(1, row-1) for c in range(1, col-1)])