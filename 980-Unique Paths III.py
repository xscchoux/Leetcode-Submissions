class Solution(object):
    def uniquePathsIII(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
# brute force DFS
        count = 0
        row, col = len(grid), len(grid[0])
        self.res = 0
        for r in range(row):
            for c in range(col):
                if grid[r][c] == 0:
                    count += 1
                elif grid[r][c] == 1:
                    start = (r, c)
        
        def dfs(start, remainCount):
            currR, currC = start
            if grid[currR][currC] == 2:
                if remainCount == -1: 
                    self.res += 1
                return
            
            for dr, dc in ((1,0),(0,1),(-1,0),(0,-1)):
                newR, newC = currR+dr, currC+dc
                if 0<=newR<row and 0<=newC<col:
                    if grid[newR][newC] == 0:
                        grid[newR][newC] = -1
                        dfs((newR, newC), remainCount-1)
                        grid[newR][newC] = 0
                    elif grid[newR][newC] == 2:
                        dfs((newR, newC), remainCount-1)
            
        dfs(start, count)
        return self.res
    
# state compression

        state = 0
        row, col = len(grid), len(grid[0])
        for r in range(row):
            for c in range(col):
                if grid[r][c] == 0 or grid[r][c] == 2:
                    state = state | 1<<(r*col+c)
                elif grid[r][c] == 1:
                    startR = r
                    startC = c
        
        def dfs(currR, currC, state):
            if grid[currR][currC] == 2:
                if state == 0: 
                    return 1
                else:
                    return 0
            
            count = 0
            for dr, dc in ((1,0),(0,1),(-1,0),(0,-1)):
                newR, newC = currR+dr, currC+dc
                if 0<=newR<row and 0<=newC<col and state&(1<<(newR*col + newC)):
                    count += dfs(newR, newC, state - (1<<(newR*col + newC)))
            return count
                                 
        res = dfs(startR, startC, state)
        return res
                    