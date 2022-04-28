from heapq import heappush, heappop
class Solution(object):
    def minimumEffortPath(self, heights):
        """
        :type heights: List[List[int]]
        :rtype: int
        """
        visited = set([(0, 0)])
        row, col = len(heights), len(heights[0])
        pq = [(0, 0, 0)]
        res = 0
        
        while pq:
            diff, currR, currC = heappop(pq)
            res = max(res, diff)
            if currR == row-1 and currC == col-1:
                return res
            visited.add((currR, currC))
            
            for dr, dc in ((1, 0), (0, 1), (-1, 0), (0, -1)):
                nr = currR + dr
                nc = currC + dc
                if 0 <= nr < row and 0 <= nc < col and (nr, nc) not in visited:
                    heappush(pq, (abs(heights[currR][currC]-heights[nr][nc]), nr, nc))
        