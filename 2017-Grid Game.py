class Solution(object):
    def gridGame(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        top, down = sum(grid[0]), 0
        res = float('inf')
        
        for upper, lower in zip(grid[0], grid[1]):
            top -= upper
            res = min(res, max(top, down))
            down += lower
        
        return res