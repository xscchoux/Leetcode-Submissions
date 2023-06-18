class Solution:
    def countPaths(self, grid: List[List[int]]) -> int:
    # O(mn)
        row, col = len(grid), len(grid[0])
        kMod = 1000000007
        @cache
        def dfs(r, c):
            tot = 1
            for dr, dc in ((1, 0), (0, 1), (-1, 0), (0, -1)):
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


    # O(mnlog(mn)), sorting + DP
        row, col = len(grid), len(grid[0])
        kMod = 10**9+7
        arr = [(i, j) for j in range(col) for i in range(row)]
        arr.sort(key = lambda x: grid[x[0]][x[1]])
        dp = [[1]*col for _ in range(row)]
        
        for r, c in arr:
            for dr, dc in ((1, 0), (0, 1), (-1, 0), (0, -1)):
                nr, nc = r+dr, c+dc
                if 0<=nr<row and 0<=nc<col and grid[nr][nc] > grid[r][c]:
                    dp[nr][nc] = (dp[nr][nc] + dp[r][c])%kMod
        
        return sum(dp[r][c]%kMod for c in range(col) for r in range(row))%kMod