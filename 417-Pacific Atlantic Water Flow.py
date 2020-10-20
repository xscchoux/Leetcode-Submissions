class Solution(object):
    def pacificAtlantic(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[List[int]]
        """
        if not matrix or not matrix[0]:
            return []
        
        pacific, atlantic = set(), set()
        
        row = len(matrix)
        col = len(matrix[0])
        
        def dfs(prev, r, c, ocean):
            if r<0 or r>=row or c<0 or c>=col or (r,c) in ocean:
                return
            if matrix[r][c]<prev:
                return
            ocean.add((r,c))
            dfs(matrix[r][c], r-1, c, ocean)
            dfs(matrix[r][c], r+1, c, ocean)
            dfs(matrix[r][c], r, c+1, ocean)
            dfs(matrix[r][c], r, c-1, ocean)
        
        for r in range(row):
            dfs(-1, r, 0, pacific)
            dfs(-1, r, col-1, atlantic)
            
        for c in range(col):
            dfs(-1, 0, c, pacific)
            dfs(-1, row-1, c, atlantic)
            
        return list(pacific & atlantic)