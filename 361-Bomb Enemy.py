class Solution(object):
    def maxKilledEnemies(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        row, col = len(grid), len(grid[0])
        up, left = [[0]*col for _ in range(row)], [[0]*col for _ in range(row)]
        down, right = [[0]*col for _ in range(row)], [[0]*col for _ in range(row)]
        
        for r in range(row):
            for c in range(col):
                if grid[r][c] == "W":
                    continue
                    
                up[r][c] += (grid[r][c] == "E")
                if r != 0:
                    up[r][c] += up[r-1][c]
                    
                left[r][c] += (grid[r][c] == "E")
                if c != 0:
                    left[r][c] += left[r][c-1]
                    
        for r in range(row-1, -1, -1):
            for c in range(col-1, -1, -1):
                if grid[r][c] == "W":
                    continue
                    
                down[r][c] += (grid[r][c] == "E")
                if r != row-1:
                    down[r][c] += down[r+1][c]
                    
                right[r][c] += (grid[r][c] == "E")
                if c != col-1:
                    right[r][c] += right[r][c+1]
        
        res = 0
        
        for r in range(row):
            for c in range(col):
                if grid[r][c] == "0":
                    res = max(res, up[r][c] + down[r][c] + left[r][c] + right[r][c])
                    
        return res