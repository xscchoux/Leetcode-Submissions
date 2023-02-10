class Solution(object):
    def maxDistance(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        row = len(grid)
        col = len(grid[0])
        
        land = []
        for r in range(row):
            for c in range(col):
                if grid[r][c] == 1:
                    land.append((r,c))
        
        if len(land) == 0 or len(land) == row*col:
            return -1
        
        count = 0
        while land:
            newLand = []
            while land:
                currR, currC = land.pop()
                for dr, dc in ((0,1), (1,0), (-1,0), (0,-1)):
                    newR = currR + dr
                    newC = currC + dc
                    if 0 <= newR < row and 0 <= newC < col and grid[newR][newC] == 0:
                        newLand.append((newR, newC))
                        grid[newR][newC] = 1
            count += 1
            land = newLand
        
        return count-1


# Updated solution
lass Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        N = len(grid)
        res = -1
        queue = collections.deque([])
        visited = [[0]*N for _ in range(N)]
        distance = -1
        
        for i in range(N):
            for j in range(N):
                if grid[i][j] == 1:
                    queue.append((i, j))
        
        if len(queue) == 0 or len(queue) == N*N:
            return -1
                    
        while queue:
            for _ in range(len(queue)):
                currR, currC = queue.popleft()
                for dr, dc in ((1, 0), (0, 1), (-1, 0), (0, -1)):
                    nxtR, nxtC = currR+dr, currC+dc
                    if 0<=nxtR<N and 0<=nxtC<N and grid[nxtR][nxtC] == 0 and visited[nxtR][nxtC] == 0:
                        visited[nxtR][nxtC] = 1
                        queue.append((nxtR, nxtC))
            distance += 1
        
        return distance