class Solution(object):
    def removeOnes(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: bool
        """
        return all(row == grid[0] or list(map(lambda x:1-x, row)) == grid[0] for row in grid)