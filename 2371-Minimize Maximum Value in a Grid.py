class Solution(object):
    def minScore(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: List[List[int]]
        """
        row, col = len(grid), len(grid[0])
        arr = []
        rowMin = [1]*row
        colMin = [1]*col
        
        for r in range(row):
            for c in range(col):
                arr.append((grid[r][c], r, c))
                
        arr.sort()
        
        for i in range(row*col):
            _, r, c = arr[i]
            grid[r][c] = max(rowMin[r], colMin[c])
            rowMin[r] = grid[r][c] + 1
            colMin[c] = grid[r][c] + 1
            
        return grid