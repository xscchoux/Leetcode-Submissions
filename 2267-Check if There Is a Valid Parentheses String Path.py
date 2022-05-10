class Solution:
    def hasValidPath(self, grid: List[List[str]]) -> bool:
        row, col = len(grid), len(grid[0])
        if grid[0][0] == ")" or grid[row-1][col-1] == "(":
            return False
        if (row + col - 1) & 1 == 1:
            return False
        
        @cache
        def dfs(currR, currC, val):
            if currR == row-1 and currC == col-1:
                if grid[currR][currC] == "(" or val != 1:
                    return False
                return True
            
            if grid[currR][currC] == "(":
                if currC < col - 1:
                    if dfs(currR, currC+1, val + 1):
                        return True
                if currR < row - 1:
                    if dfs(currR+1, currC, val + 1):
                        return True
            else:
                if currC < col - 1 and val - 1 >= 0:
                    if dfs(currR, currC+1, val - 1):
                        return True
                if currR < row - 1 and val - 1 >= 0:
                    if dfs(currR+1, currC, val - 1):
                        return True
            return False
        res = dfs(0, 0, 0)
        return res