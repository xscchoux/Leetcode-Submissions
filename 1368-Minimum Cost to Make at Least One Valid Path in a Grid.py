from heapq import heappush, heappop
class Solution(object):
    def minCost(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        row, col = len(grid), len(grid[0])
        pq = [(0, 0, 0)]
        visited = set()
        directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        
        while pq:
            cost, r, c = heappop(pq)
            if r == row-1 and c == col-1:
                return cost
            if (r, c) in visited:
                continue
            visited.add((r, c))
            
            for ind, dx in enumerate(directions):
                nr, nc = r+dx[0], c+dx[1]
                if 0<=nr<row and 0<=nc<col and (nr, nc) not in visited:
                    if ind + 1 == grid[r][c]:
                        heappush(pq, (cost, nr, nc))
                    else:
                        heappush(pq, (cost+1, nr, nc))
        
        return -1