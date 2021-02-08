class Solution(object):
    def maxDistance(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        row = len(grid)
        col = len(grid[0])
        
        land = []
        for r in range(row):
            for c in range(col):
                if grid[r][c] == 1:
                    land.append((r,c))
        
        if len(land) == 0 or len(land) == row*col:
            return -1
        
        count = 0
        while land:
            newLand = []
            while land:
                currR, currC = land.pop()
                for dr, dc in ((0,1), (1,0), (-1,0), (0,-1)):
                    newR = currR + dr
                    newC = currC + dc
                    if 0 <= newR < row and 0 <= newC < col and grid[newR][newC] == 0:
                        newLand.append((newR, newC))
                        grid[newR][newC] = 1
            count += 1
            land = newLand
        
        return count-1