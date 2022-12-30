class Solution:
    def isThereAPath(self, grid: List[List[int]]) -> bool:
        
        row, col = len(grid), len(grid[0])
        
        if (row + col - 1)%2:
            return False
        
        @cache
        def dfs(r, c, diff):
            
            if grid[r][c] == 0:
                diff += 1
            else:
                diff -= 1
                
            if r == row-1 and c == col-1:
                return diff == 0

            if r+1 < row and dfs(r+1, c, diff):
                return True
            if c+1 < col and dfs(r, c+1, diff):
                return True
            
            return False
        
        return dfs(0, 0, 0)