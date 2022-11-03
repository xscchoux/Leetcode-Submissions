class Solution(object):
    def findBall(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: List[int]
        """
        res = [-1]*len(grid[0])
        stack = []
        for i in range(len(grid[0])):
            stack.append((i, i)) # index of ball, position, direction

        for r in range(len(grid)):
            newStack = []
            for ind, col in stack:
                newCol = col + grid[r][col]
                if newCol < 0 or newCol >= len(grid[0]) or grid[r][col] != grid[r][newCol]:
                    continue
                newStack.append((ind, newCol))
            stack = newStack

        for ind, pos in stack:
            res[ind] = pos
            
        return res