class Solution(object):
    def orangesRotting(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        row, col = len(grid), len(grid[0])
        
        queue = deque()
        fresh = 0
        for r in range(row):
            for c in range(col):
                if grid[r][c] == 2:
                    queue.append((r, c))
                elif grid[r][c] == 1:
                    fresh += 1
        
        minute = 0
        visited = set()
        while queue:
            for _ in range(len(queue)):
                currR, currC = queue.popleft()
                for dr, dc in ((1,0), (0,1), (-1,0), (0,-1)):
                    newR, newC = currR + dr, currC + dc
                    if 0<=newR<row and 0<=newC<col and grid[newR][newC] == 1 and (newR, newC) not in visited:
                        visited.add((newR, newC))
                        queue.append((newR, newC))
            if not queue:
                break
            minute += 1
            
        return minute if len(visited) == fresh else -1