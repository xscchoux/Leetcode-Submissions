class Solution(object):
    def largestIsland(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        N = len(grid)
        area = dict()
        
        def dfs(r, c, index):
            area = 0
            for dr, dc in ((1,0),(0,1),(-1,0),(0,-1)):
                newR, newC = r+dr, c+dc
                if 0<=newR<N and 0<=newC<N and grid[newR][newC] == 1:
                    grid[newR][newC] = index
                    area += 1 + dfs(newR, newC, index)
            return area
        
        index = 2
        for r in range(N):
            for c in range(N):
                if grid[r][c] == 1:
                    grid[r][c] = index
                    area[index] = 1 + dfs(r, c, index)
                    index += 1
        
        res = max(area.values() or [0])
        
        for r in range(N):
            for c in range(N):
                if grid[r][c] == 0:
                    neighbors = set()
                    for dr, dc in ((1,0),(0,1),(-1,0),(0,-1)):
                        newR = r + dr
                        newC = c + dc
                        if 0<=newR<N and 0<=newC<N and grid[newR][newC] > 1:
                            neighbors.add(grid[newR][newC])
                        res = max(res, 1 + sum([area[island] for island in neighbors]))
        return res    