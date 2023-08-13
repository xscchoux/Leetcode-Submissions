# Heap + binary search
from heapq import *
class Solution:
    def maximumSafenessFactor(self, grid: List[List[int]]) -> int:
        n = len(grid)
        if grid[0][0] == 1 or grid[n-1][n-1] == 1:
            return 0

        visited = [[False]*n for _ in range(n)]
        queue = deque([])
        for r in range(n):
            for c in range(n):
                if grid[r][c] == 1:
                    queue.append((r, c))
                    visited[r][c] = True
        
        dist = [[0]*n for _ in range(n)]
        
        step = 0
        
        while queue:
            for _ in range(len(queue)):
                r, c = queue.popleft()
                dist[r][c] = step
                for dr, dc in ((0, 1), (1, 0), (0, -1), (-1, 0)):
                    nr, nc = r+dr, c+dc
                    if 0<=nr<n and 0<=nc<n and not visited[nr][nc]:
                        visited[nr][nc] = True
                        queue.append((nr, nc))
            step += 1
        
        pq = [(-dist[0][0], 0, 0)]
        visited = [[False]*n for _ in range(n)]
        while pq:
            d, r, c = heappop(pq)
            if r == n-1 and c == n-1:
                return -d
            if visited[r][c]:
                continue
            visited[r][c] = True
            for dr, dc in ((1,0),(0,1),(-1,0),(0,-1)):
                nr, nc = r+dr, c+dc
                if 0<=nr<n and 0<=nc<n and not visited[nr][nc]:
                    heappush(pq, ( -min(-d, dist[nr][nc]) ,nr, nc))

# BFS + binary search
class Solution:
    def maximumSafenessFactor(self, grid: List[List[int]]) -> int:        

        n = len(grid)
        if grid[0][0] == 1 or grid[n-1][n-1] == 1:
            return 0

        visited = [[False]*n for _ in range(n)]
        queue = deque([])
        for r in range(n):
            for c in range(n):
                if grid[r][c] == 1:
                    queue.append((r, c))
                    visited[r][c] = True
        
        dist = [[0]*n for _ in range(n)]
        
        step = 0
        
        while queue:
            for _ in range(len(queue)):
                r, c = queue.popleft()
                dist[r][c] = step
                for dr, dc in ((0, 1), (1, 0), (0, -1), (-1, 0)):
                    nr, nc = r+dr, c+dc
                    if 0<=nr<n and 0<=nc<n and not visited[nr][nc]:
                        visited[nr][nc] = True
                        queue.append((nr, nc))
            step += 1      
        
        
        def isOK(bound):
            if dist[0][0] < bound:
                return False
            visited = [[False]*n for _ in range(n)]
            visited[0][0] = True
            queue = deque([(0, 0)])
            
            while queue:
                for _ in range(len(queue)):
                    currR, currC = queue.popleft()
                    if currR == n-1 and currC == n-1:
                        return True
                    for dr, dc in ((1, 0), (0, 1), (-1, 0), (0, -1)):
                        nr = currR+dr
                        nc = currC+dc
                        if 0<=nr<n and 0<=nc<n and not visited[nr][nc] and dist[nr][nc] >= bound:
                            visited[nr][nc] = True
                            queue.append((nr, nc))
                            
            return False
        
        
        left, right = 0, n+n
        while left + 1 < right:
            mid = left + (right-left)//2
            if isOK(mid):
                left = mid
            else:
                right = mid
        
        if isOK(right):
            return right
        else:
            return left