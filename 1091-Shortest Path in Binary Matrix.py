class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        N = len(grid)
        if grid[0][0] or grid[N-1][N-1]:
            return -1

        queue = deque([(0, 0)])
        directions = [(1, 0), (1, -1), (1, 1), (0, 1), (0, -1), (-1, 0), (-1, -1), (-1, 1)]
        step = 1
        grid[0][0] = 1
        
        while queue:
            for _ in range(len(queue)):
                currR, currC = queue.popleft()
                if currR == N-1 and currC == N-1:
                    return step
                for dr, dc in directions:
                    nxtR, nxtC = currR+dr, currC+dc
                    if 0<=nxtR<N and 0<=nxtC<N and grid[nxtR][nxtC] == 0:
                        grid[nxtR][nxtC] = 1
                        queue.append((nxtR, nxtC))
            step += 1
        
        return -1