class Solution(object):
    def containsCycle(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: bool
        """
# use array

        row, col = len(grid), len(grid[0])
        visited = [[False]*col for _ in range(row)]
        
        def dfs(r, c, prev=None):
            visited[r][c] = True
            for dr, dc in ((1,0), (0,1), (-1,0), (0, -1)):
                nr = r+dr
                nc = c+dc
                if 0<=nr<row and 0<=nc<col and grid[nr][nc] == grid[r][c]:
                    if not visited[nr][nc]:
                        if dfs(nr, nc, (r, c)):
                            return True
                    else:
                        if (nr, nc) != prev:
                            return True
            return False
            
        for r in range(row):
            for c in range(col):
                if not visited[r][c]:
                    if dfs(r, c):
                        return True
        return False
    
# use set
        
        row, col = len(grid), len(grid[0])
        visited = set()
        
        def dfs(r, c, prev=None):
            visited.add((r, c))
            for dr, dc in ((1,0), (0,1), (-1,0), (0, -1)):
                nr = r+dr
                nc = c+dc
                if 0<=nr<row and 0<=nc<col and grid[nr][nc] == grid[r][c]:
                    if (nr, nc) not in visited:
                        if dfs(nr, nc, (r, c)):
                            return True
                    else:
                        if (nr, nc) != prev:
                            return True
            return False
            
        for r in range(row):
            for c in range(col):
                if (r, c) not in visited:
                    if dfs(r, c):
                        return True
        return False