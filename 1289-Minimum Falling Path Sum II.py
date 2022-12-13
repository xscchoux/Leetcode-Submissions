from sortedcontainers import SortedList
import heapq
class Solution(object):
    def minFallingPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
# first try
        n = len(grid)
            
        for r in range(1, n):
            prev = SortedList()
            for i in range(n):
                prev.add(grid[r-1][i])
            for c in range(n):
                prev.remove(grid[r-1][c])
                grid[r][c] += prev[0]
                prev.add(grid[r-1][c])
        
        return min(grid[-1])

        
# heap
        for r in range(1, len(grid)):
            q = heapq.nsmallest(2, grid[r-1])
            for c in range(len(grid)):
                if grid[r-1][c] == q[0]:
                    grid[r][c] += q[1]
                else:
                    grid[r][c] += q[0]
        
        return min(grid[-1])