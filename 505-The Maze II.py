from heapq import heappush, heappop
class Solution(object):
    def shortestDistance(self, maze, start, destination):
        """
        :type maze: List[List[int]]
        :type start: List[int]
        :type destination: List[int]
        :rtype: int
        """
# Dijkstra 1
        visited = set()
        row, col = len(maze), len(maze[0])
        pq = []
        heappush(pq, (0, start[0], start[1]))
        
        while pq:
            step, currR, currC = heappop(pq)
            if currR == destination[0] and currC == destination[1]:
                    return step
            visited.add((currR, currC))
            for dr, dc in ((1, 0), (0, 1), (-1, 0), (0, -1)):
                R, C, currStep = currR, currC, step
                while 0<=R+dr<row and 0<=C+dc<col and maze[R+dr][C+dc] == 0:
                    R += dr
                    C += dc
                    currStep += 1
                if (R, C) not in visited:
                    heappush(pq, (currStep, R, C))
        return -1
    
    
# Dijkstra 2
        row, col = len(maze), len(maze[0])
        pq = []
        dist = [[float('inf')]*col for _ in range(row)]
        heappush(pq, (0, start[0], start[1]))
        dist[start[0]][start[1]] = 0
        
        while pq:
            step, currR, currC = heappop(pq)
            for dr, dc in ((1, 0), (0, 1), (-1, 0), (0, -1)):
                R, C, count = currR, currC, 0
                while 0<=R+dr<row and 0<=C+dc<col and maze[R+dr][C+dc] == 0:
                    R += dr
                    C += dc
                    count += 1
                if dist[currR][currC] + count < dist[R][C]:
                    dist[R][C] = dist[currR][currC] + count
                    heappush(pq, (dist[currR][currC] + count, R, C)) 
        if dist[destination[0]][destination[1]] == float('inf'):
            return -1
        else:
            return dist[destination[0]][destination[1]]