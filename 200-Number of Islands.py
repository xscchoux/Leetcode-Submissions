class Solution(object):
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        row, col = len(grid), len(grid[0])
        
        def dfs(r, c):
            grid[r][c] = "0"
            for dr, dc in ((1,0),(0,1),(-1,0),(0,-1)):
                newR, newC = r + dr, c + dc
                if 0<=newR<row and 0<=newC<col and grid[newR][newC] == '1':
                    dfs(newR, newC)
        res = 0
        
        for r in range(row):
            for c in range(col):
                if grid[r][c] == '1':
                    dfs(r,c)
                    res += 1         
        return res