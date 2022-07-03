class Solution:
    def countPaths(self, grid: List[List[int]]) -> int:
        row, col = len(grid), len(grid[0])
        kMod = 1000000007
        @cache
        def dfs(r, c):
            # print(r, c)
            tot = 1
            for dr, dc in ((1,0), (0, 1), (-1, 0), (0, -1)):
                nr = r + dr
                nc = c + dc
                if 0<=nr<row and 0<=nc<col and grid[nr][nc] > grid[r][c]:
                    tot = (tot + dfs(nr, nc))%kMod
            return tot
        
        res = 0
        for r in range(row):
            for c in range(col):
                res = (res + dfs(r, c))%kMod
        return res