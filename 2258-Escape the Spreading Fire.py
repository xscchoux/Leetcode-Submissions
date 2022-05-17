class Solution(object):
    def maximumMinutes(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
# BFS + binary search
        row, col = len(grid), len(grid[0])
        queue = collections.deque([])

        dist = [[1000090001]*col for _ in range(row)]
        for r in range(row):
            for c in range(col):
                if grid[r][c] == 1:
                    dist[r][c] = 0
                    queue.append((0, r, c))
        
        while queue:
            for _ in range(len(queue)):
                d, currR, currC = queue.popleft()
                for dr, dc in ((1, 0), (0, 1), (-1, 0), (0, -1)):
                    nxtR = currR + dr
                    nxtC = currC + dc
                    if 0<=nxtR<row and 0<=nxtC<col and grid[nxtR][nxtC] != 2 and dist[nxtR][nxtC] == 1000090001:
                        dist[nxtR][nxtC] = d + 1
                        queue.append((d+1, nxtR, nxtC))
        
        def bfs(startTime):
            visited = set([(0, 0)])
            if startTime >= dist[0][0]:
                return False
            queue = collections.deque([(startTime, 0, 0)])
            
            while queue:
                for _ in range(len(queue)):
                    d, currR, currC = queue.popleft()
                    for dr, dc in ((1,0), (0,1), (-1,0), (0,-1)):
                        nxtR = currR+dr
                        nxtC = currC+dc
                        if 0<=nxtR<row and 0<=nxtC<col and grid[nxtR][nxtC] != 2 and (nxtR, nxtC) not in visited:
                            visited.add((nxtR, nxtC))
                            if d + 1 < dist[nxtR][nxtC]:
                                queue.append((d+1, nxtR, nxtC))
                        if nxtR == row-1 and nxtC == col-1 and grid[nxtR][nxtC] != 2 and d + 1 <= dist[nxtR][nxtC]:
                            return True
            return False
        
        left, right = 0, 1000000000
        
        while left + 1 < right:
            mid = left + (right-left)//2
            if bfs(mid):
                left = mid
            else:
                right = mid

        if bfs(right):
            return right
        elif bfs(left):
            return left
        else:
            return -1


# optimal solution

        row, col = len(grid), len(grid[0])
        fire = [[float('inf')]*col for _ in range(row)]
        people = [[float('inf')]*col for _ in range(row)]
        
        def bfs(_type, arr):
            visited = set()
            queue = collections.deque([])
            if _type == "fire":
                for r in range(row):
                    for c in range(col):
                        if grid[r][c] == 1:
                            visited.add((r, c))
                            queue.append((0, r, c))
            elif _type == "people":
                visited.add((0, 0))
                queue.append((0, 0, 0))
            
            while queue:
                for _ in range(len(queue)):
                    d, currR, currC = queue.popleft()
                    for dr, dc in ((1,0), (0,1), (-1,0), (0,-1)):
                        nxtR = currR + dr
                        nxtC = currC + dc
                        if 0<=nxtR<row and 0<=nxtC<col and grid[nxtR][nxtC] != 2 and (nxtR, nxtC) not in visited:
                            visited.add((nxtR, nxtC))
                            arr[nxtR][nxtC] = d+1
                            queue.append((d+1, nxtR, nxtC))
        
        bfs("fire", fire)
        bfs("people", people)
        
        if people[row-1][col-1] == float('inf') or fire[row-1][col-1] + 1 <= people[row-1][col-1]:
            return -1
        if fire[row-1][col-1] == float('inf'):
            return 1000000000
        
        diff = fire[-1][-1] - people[-1][-1]
        
        if fire[-1][-2] - people[-1][-2] > diff or fire[-2][-1] - people[-2][-1] > diff:
            return diff
        
        return diff - 1