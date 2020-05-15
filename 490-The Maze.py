from collections import deque
class Solution(object):
    def hasPath(self, maze, start, destination):
        """
        :type maze: List[List[int]]
        :type start: List[int]
        :type destination: List[int]
        :rtype: bool
        """
# BFS
        queue = deque([(start[0],start[1])])
        seen = set()
        row = len(maze)
        col = len(maze[0])
        seen.add((start[0],start[1]))
        while queue:
            for _ in range(len(queue)):
                currR, currC = queue.popleft()
                if currR == destination[0] and currC == destination[1]:
                    return True
                for dr, dc in ((1,0),(0,1),(-1,0),(0,-1)):
                    newR = currR
                    newC = currC
                    while 0<=newR<row and 0<=newC<col and maze[newR][newC] == 0:
                        newR += dr
                        newC += dc
                    newR -= dr
                    newC -= dc
                    if (newR, newC) not in seen:
                        seen.add((newR, newC))
                        queue.append((newR,newC))
        return False