class Solution(object):
    def shortestPath(self, grid, k):
        """
        :type grid: List[List[int]]
        :type k: int
        :rtype: int
        """
        row = len(grid)
        col = len(grid[0])
        
        if row + col -2  <= k:
            return row+col-2
        
        queue = collections.deque([(0, 0, k, 0)])
        usedStates = set()
        usedStates.add((0,0,k))
        
        while queue:
            for _ in range(len(queue)):
                currR, currC, remain, step = queue.popleft()
                if currR == row-1 and currC == col-1:
                    return step
                for dr, dc in ((0,1),(1,0),(0,-1),(-1,0)):
                    newR, newC = currR + dr, currC + dc
                    if 0<=newR<row and 0<=newC<col:
                        if grid[newR][newC] == 1 and remain >= 1 and (newR, newC, remain-1) not in usedStates:
                            usedStates.add((newR, newC, remain-1))
                            queue.append((newR, newC, remain-1, step+1))
                        elif grid[newR][newC] == 0 and (newR, newC, remain) not in usedStates:
                            usedStates.add((newR, newC, remain))
                            queue.append((newR, newC, remain, step+1))

        return -1