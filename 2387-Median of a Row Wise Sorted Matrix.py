from bisect import bisect_right
class Solution(object):
    def matrixMedian(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        row, col = len(grid), len(grid[0])
        mx, mn = grid[-1][-1], grid[0][0]
        num = row*col//2 + 1
        
        def count(curr):
            res = 0
            for row in grid:
                res += bisect_right(row, curr)
            return res
        
        for row in grid:
            mx = max(row[-1], mx)
            mn = min(row[0], mn)
            
        while mn + 1 < mx:
            mid = mn + (mx-mn)//2
            if count(mid) < num:
                mn = mid
            else:
                mx = mid
        
        if count(mn) >= num:
            return mn
        else:
            return mx