from collections import deque
class Solution(object):
    def shortestDistance(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        row = len(grid)
        col = len(grid[0])
        res = [[0]*col for _ in range(row)]
        reachableCount = [[0]*col for _ in range(row)]
        
        zeros = 0
        ones = 0
        offices = []
        for r in range(row):
            for c in range(col):
                if grid[r][c] != 0:
                    res[r][c] = float('inf')
                    if grid[r][c] == 1:
                        offices.append((r,c))
                        ones += 1
                else:
                    zeros+=1
        
        if not zeros:
            return -1
                        
        for office in offices:
            queue = deque([])
            queue.append((office[0],office[1],0))
            visited = set()
            visited.add(office)
            visitedOffice = 0
            while queue:
                size = len(queue)
                for _ in range(size):
                    currR, currC, step = queue.popleft()
                    for dr, dc in ((0,1),(1,0),(0,-1),(-1,0)):
                        newR = currR + dr
                        newC = currC + dc
                        if 0<=newR<row and 0<=newC<col and (newR, newC) not in visited:
                            if grid[newR][newC] == 0:
                                queue.append((newR, newC, step+1))
                                res[newR][newC] += step+1
                                visited.add((newR,newC))
                                reachableCount[newR][newC] += 1
                            elif grid[newR][newC] == 1:
                                visitedOffice +=1
                                visited.add((newR, newC))            
            if visitedOffice+1 != ones:
                return -1

        minimum = float('inf')
        for r in range(row):
            for c in range(col):
                if reachableCount[r][c] == ones and grid[r][c] == 0:
                    minimum = min(res[r][c], minimum)
        
        if minimum == float('inf'):
            return -1
        return minimum