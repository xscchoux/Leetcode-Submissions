import heapq
class Solution(object):
    def swimInWater(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
# BFS + priority queue, O(N^2*logN^2)

        N = len(grid)
        visited = set()
        visited.add((0,0))
        pq = []
        heappush(pq, (grid[0][0], 0, 0))
        maxHeight = 0
        
        while pq:
            height, r, c = heappop(pq)
            maxHeight = max(maxHeight, height)
            if r == c == N-1:
                return maxHeight
            for dr, dc in ((1,0),(0,1),(-1,0),(0,-1)):
                newR = r + dr
                newC = c + dc
                if 0<=newR<N and 0<=newC<N and (newR, newC) not in visited:
                    visited.add((newR, newC))
                    heappush(pq, (grid[newR][newC], newR, newC))
        
# BFS + binary search, O(N^2*logN^2)
        N = len(grid)
    
        def bfs(mid):
            if grid[0][0] > mid:
                return False
            
            queue = [(0,0)]
            visited = set()
            visited.add((0,0))
            
            while queue:
                r, c = queue.pop()
                if r == c == N-1:
                    return True
                for dr, dc in ((0,1),(1,0),(-1,0),(0,-1)):
                    newR = r + dr
                    newC = c + dc
                    if 0<=newR<N and 0<=newC<N and (newR, newC) not in visited and grid[newR][newC] <= mid:
                        visited.add((newR, newC))
                        queue.append((newR, newC))
            return False
        
        left, right = 0, (N**2)-1
        
        while left + 1 < right:
            mid = left + (right-left)//2
            if bfs(mid):
                right = mid
            else:
                left = mid
        
        if bfs(left):
            return left
        else:
            return right
        
        
# Dijkstra, O(N^2*logN^2)
        N = len(grid)
        cost = [[float('inf')]*N for _ in range(N)]
        cost[0][0] = grid[0][0]
        pq = [(cost[0][0], 0, 0)]
        visited = set()
        
        while pq:
            currMaxHeight, r, c = heappop(pq)
            visited.add((r,c))
            if r == c == N-1:
                return currMaxHeight
            for dr, dc in ((1,0),(0,1),(-1,0),(0,-1)):
                newR = r + dr
                newC = c + dc
                if 0<=newR<N and 0<=newC<N and (newR, newC) not in visited:
                    diff = max(0, grid[newR][newC] - currMaxHeight)
                    if diff + currMaxHeight < cost[newR][newC]:
                        cost[newR][newC] = diff+currMaxHeight
                        heappush(pq, (currMaxHeight + diff, newR, newC))
                        
# Kruskal's algorithm, disjoint set (union-find), O(N^2*logN^2)
        N = len(grid)
        positions = sorted( [(r, c) for r in range(N) for c in range(N)], key = lambda x: grid[x[0]][x[1]] )
        score = [1]*(N*N)
        parent = list(range(N*N))
        used = set()
        
        def find(x):
            # with path compression
            tmp = x
            path = []
            while parent[tmp] != tmp:
                path.append(tmp)
                tmp = parent[tmp]
            for node in path:
                parent[node] = tmp
            return tmp
        
        def union(x, y):
            px = find(x)
            py = find(y)
            if px != py:
                if score[px] > score[py]:
                    parent[py] = px
                    score[px] += score[py]
                else:
                    parent[px] = py
                    score[py] += score[px]
        
        
        for r, c in positions:
            used.add((r,c))
            
            for dr, dc in ((1,0),(0,1),(-1,0),(0,-1)):
                newR = r + dr
                newC = c + dc
                if 0<=newR<N and 0<=newC<N and (newR, newC) in used:
                    union(r*N+c, newR*N+newC)
                    
            if find(0) == find(N*N-1):
                return grid[r][c]