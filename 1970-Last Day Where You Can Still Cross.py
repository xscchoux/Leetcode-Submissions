class Solution:
    def latestDayToCross(self, row: int, col: int, cells: List[List[int]]) -> int:
# BFS + binary search
        def isOK(step):
            graph = [[0]*col for _ in range(row)]
            for i in range(len(cells))[:step]:
                r, c = cells[i][0]-1, cells[i][1]-1
                graph[r][c] = 1
            
            queue = deque()
            for c in range(col):
                if graph[0][c] == 0:
                    graph[0][c] = 1
                    queue.append((0, c))
            
            while queue:
                for _ in range(len(queue)):
                    currR, currC = queue.popleft()
                    if currR == row-1:
                        return True
                    for dr, dc in ((1, 0), (0, 1), (-1, 0), (0, -1)):
                        nr, nc = currR+dr, currC+dc
                        if 0<=nr<row and 0<=nc<col and graph[nr][nc] == 0 and graph[nr][nc] == 0:
                            graph[nr][nc] = 1
                            queue.append((nr, nc))
            return False
        
        left, right = 0, len(cells)
        
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