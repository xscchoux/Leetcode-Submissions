from heapq import heappush, heappop
class Solution(object):
    def highestRankedKItems(self, grid, pricing, start, k):
        """
        :type grid: List[List[int]]
        :type pricing: List[int]
        :type start: List[int]
        :type k: int
        :rtype: List[List[int]]
        """
        pq = []
        row, col = len(grid), len(grid[0])
        queue = collections.deque([(start[0], start[1], 0)])
        visited = set([(start[0], start[1])])
        heappush(pq, (0, grid[start[0]][start[1]], start[0], start[1]))
        res = []

        while queue:
            for _ in range(len(queue)):
                r, c, step = queue.popleft()
                for dr, dc in ((0, 1), (1,0), (-1,0), (0,-1)):
                    nr, nc = r+dr, c+dc
                    if 0<=nr<row and 0<=nc<col and grid[nr][nc] != 0 and (nr, nc) not in visited:
                        visited.add((nr, nc))
                        if pricing[0] <= grid[nr][nc] <= pricing[1]:
                            heappush(pq, (step+1, grid[nr][nc], nr, nc))
                        queue.append((nr, nc, step+1))
                        
        while pq and k > 0:
            _, val, r, c = heappop(pq)
            if pricing[0] <= val <= pricing[1]:
                res.append([r, c])
                k -= 1
        
        return res