from heapq import heappush, heappop
class Solution:
    def minimumTime(self, grid: List[List[int]]) -> int:
        row, col = len(grid), len(grid[0])
        pq = [(0, 0, 0)]  # (time, row, col)
        visited = {(0, 0)} # (row, col)
        directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        if grid[0][1] > 1 and grid[1][0] > 1:
            return -1
        
        while pq:
            time, currR, currC = heappop(pq)
            if currR == row - 1 and currC == col - 1:
                return time

            for dr, dc in directions:
                nxtR, nxtC = currR + dr, currC + dc
                if 0 <= nxtR < row and 0 <= nxtC < col and (nxtR, nxtC) not in visited:
                    visited.add((nxtR, nxtC))
                    newTime = time + 1
                    if grid[nxtR][nxtC] > time:
                        diff = grid[nxtR][nxtC] - time
                        if diff%2 == 0:
                            newTime = max(newTime, grid[nxtR][nxtC] + 1)
                        else:
                            newTime = max(newTime, grid[nxtR][nxtC])                            
                    heappush(pq, (newTime, nxtR, nxtC))

        return -1
            