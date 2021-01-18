class Solution(object):
    def minTotalDistance(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
# sorting
        row = len(grid)
        col = len(grid[0])
        rowArr, colArr = [], []
        
        for r in range(row):
            for c in range(col):
                if grid[r][c] == 1:
                    rowArr.append(r)
                    colArr.append(c)

        def minDistance(arr):
            arr.sort()
            left, right = 0, len(arr)-1
            res = 0
            while left<right:
                res += arr[right]-arr[left]
                left += 1
                right -= 1
            return res
        
        return minDistance(rowArr) + minDistance(colArr)
    
# without sorting

        row = len(grid)
        col = len(grid[0])
        rowArr, colArr = [], []
        
        for r in range(row):
            for c in range(col):
                if grid[r][c] == 1:
                    rowArr.append(r)
                    
        for c in range(col):
            for r in range(row):
                if grid[r][c] == 1:
                    colArr.append(c)
                    
        def minDistance(arr):
            origin = arr[len(arr)//2]
            res = 0
            for i in range(len(arr)):
                res += abs(arr[i]-origin)
            
            return res
        
        return minDistance(rowArr) + minDistance(colArr)