from heapq import heappush, heappop
class Solution:
    def maximumMinimumPath(self, grid: List[List[int]]) -> int:
        row, col = len(grid), len(grid[0])
        visited = set((0,0))
        pq = [(-grid[0][0], 0, 0)]
        res = grid[0][0]
    
        while pq:
            curr, r, c = heappop(pq)
            res = min(res, -curr)
            if r == row-1 and c == col-1:
                return res
            for dr, dc in ((1,0), (0,1), (-1,0), (0,-1)):
                nr = r + dr
                nc = c + dc
                if 0<=nr<row and 0<=nc<col and (nr, nc) not in visited:
                    heappush(pq, (-1*grid[nr][nc], nr, nc))
                    visited.add((nr, nc))