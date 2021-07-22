class Solution(object):
    def getFood(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        row, col = len(grid), len(grid[0])
        
        curr = target = None
        for r in range(row):
            for c in range(col):
                if grid[r][c] == "*":
                    curr = (r, c)
                elif grid[r][c] == "#":
                    target = (r, c)
        if not target:
            return -1
        
        queue = collections.deque([curr])
        visited = set()
        visited.add(curr)
        step = 0
        
        while queue:
            for _ in range(len(queue)):
                currR, currC = queue.popleft()
                if currR == target[0] and currC == target[1]:
                    return step
                for dr, dc in ((1,0), (0,1), (-1,0), (0,-1)):
                    newR, newC = currR + dr, currC + dc
                    if 0<=newR<row and 0<=newC<col and (newR, newC) not in visited:
                        if grid[newR][newC] == "O":
                            visited.add((newR,newC))
                            queue.append((newR, newC))
                        elif grid[newR][newC] == "#":
                            return step+1
            step += 1
        return -1