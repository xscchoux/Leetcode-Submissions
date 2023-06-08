class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        res = 0
        currR = m - 1
        currC = 0
        
        while currR >= 0 and currC < n:
            if grid[currR][currC] < 0:
                res += n - currC
                currR -= 1
            else:
                currC += 1
        
        return res