from collections import deque
class Solution(object):
    def shortestPathBinaryMatrix(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """

        if grid[0][0] == 1:
            return -1
        
        queue = deque([])
        queue.append((0,0,1))
        
        row = len(grid)
        col = len(grid[0])
        visited = set()
        visited.add((0,0))
        
        while queue:
            size = len(queue)
            for _ in range(size):
                r, c, step = queue.popleft()
                if r == row-1 and c == col-1:
                    return step
                for dr, dc in ((1,0),(0,1),(0,-1),(-1,0),(1,1),(1,-1),(-1,1),(-1,-1)):
                    newR = r + dr
                    newC = c + dc
                    if 0<=newR<row and 0<=newC<col and (newR,newC) not in visited and grid[newR][newC] == 0:
                        visited.add((newR,newC))
                        queue.append((newR, newC, step+1))
        return -1