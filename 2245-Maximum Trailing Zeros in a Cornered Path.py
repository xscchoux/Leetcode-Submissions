class Solution:
    def maxTrailingZeros(self, grid: List[List[int]]) -> int:
        row, col = len(grid), len(grid[0])
        
        @cache
        def count2(num):
            res = 0
            while num%2 == 0:
                res+=1
                num //= 2
            return res
        
        @cache
        def count5(num):
            res = 0
            while num%5 == 0:
                res+=1
                num //= 5
            return res
        
        up = [[[0 for _ in range(2)] for _ in range(col)] for _ in range(row)]
        down = [[[0 for _ in range(2)] for _ in range(col)] for _ in range(row)]
        left = [[[0 for _ in range(2)] for _ in range(col)] for _ in range(row)]
        right = [[[0 for _ in range(2)] for _ in range(col)] for _ in range(row)]

        for c in range(col):
            for upR in range(row):
                if upR == 0:
                    up[upR][c][0] = count2(grid[upR][c])
                    up[upR][c][1] = count5(grid[upR][c])
                else:
                    up[upR][c][0] = up[upR-1][c][0] + count2(grid[upR][c])
                    up[upR][c][1] = up[upR-1][c][1] + count5(grid[upR][c])
        
        for r in range(row):
            for leftC in range(col):
                if leftC == 0:
                    left[r][leftC][0] = count2(grid[r][leftC])
                    left[r][leftC][1] = count5(grid[r][leftC])
                else:
                    left[r][leftC][0] = left[r][leftC-1][0] + count2(grid[r][leftC])
                    left[r][leftC][1] = left[r][leftC-1][1] + count5(grid[r][leftC])

        res = 0
        
        for r in range(row):
            for c in range(col):
                # up + left
                num2, num5 = count2(grid[r][c]), count5(grid[r][c])
                res = max(res, min(up[r][c][0]+left[r][c][0]-num2, up[r][c][1]+left[r][c][1]-num5))
                # down + left
                res = max(res, min(up[row-1][c][0]-up[r][c][0]+left[r][c][0], up[row-1][c][1]-up[r][c][1]+left[r][c][1]))
                # up + right
                res = max(res, min(up[r][c][0]+left[r][col-1][0]-left[r][c][0], up[r][c][1]+left[r][col-1][1]-left[r][c][1]))
                # down + right
                res = max(res, min(up[row-1][c][0]-up[r][c][0]+left[r][col-1][0]-left[r][c][0]+num2, up[row-1][c][1]-up[r][c][1]+left[r][col-1][1]-left[r][c][1]+num5))
                
        return res
                