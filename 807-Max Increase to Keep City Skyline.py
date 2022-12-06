class Solution:
    def maxIncreaseKeepingSkyline(self, grid: List[List[int]]) -> int:
        N = len(grid)
        maxRow, maxCol = [0]*N, [0]*N
        res = 0
        
        for r in range(N):
            for c in range(N):
                maxRow[r] = max(grid[r][c], maxRow[r])
                maxCol[c] = max(grid[r][c], maxCol[c])
        
        for r in range(N):
            for c in range(N):
                res += min(maxRow[r], maxCol[c]) - grid[r][c]
        
        return res