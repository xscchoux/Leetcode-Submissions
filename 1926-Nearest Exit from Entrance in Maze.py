class Solution(object):
    def nearestExit(self, maze, entrance):
        """
        :type maze: List[List[str]]
        :type entrance: List[int]
        :rtype: int
        """
        visited = set()
        row = len(maze)
        col = len(maze[0])
        
        visited.add(tuple(entrance))
        queue = collections.deque([(tuple(entrance))])
        step = 0
        
        while queue:
            for _ in range(len(queue)):
                currR, currC = queue.popleft()
                if (currR, currC) != tuple(entrance) and (currR==row-1 or currC==col-1 or currR==0 or currC==0):
                    return step
                
                for dr, dc in ((1,0),(0,1),(-1,0),(0,-1)):
                    newR = currR + dr
                    newC = currC +dc
                    if 0<=newR<row and 0<=newC<col and maze[newR][newC] == "." and (newR, newC) not in visited:
                        visited.add((newR, newC))
                        queue.append((newR, newC))   
            step += 1
        
        return -1