class Solution(object):
    def setZeroes(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: None Do not return anything, modify matrix in-place instead.
        """

# Time: O(mn)
# Space: O(m+n)     
        row = len(matrix)
        col = len(matrix[0])
        colSet = set()
        rowSet = set()
        
        for r in range(row):
            for c in range(col):
                if matrix[r][c] == 0:
                    rowSet.add(r)
                    colSet.add(c)
        
        for r in range(row):
            for c in range(col):
                if r in rowSet or c in colSet:
                    matrix[r][c] = 0
                    
# Time: O(mn)
# Space: O(m+n)
        row = len(matrix)
        col = len(matrix[0])
        firstRowZero = False
        firstColZero = False
        
        for r in range(row):
            for c in range(col):
                if matrix[r][c] == 0:
                    matrix[r][0] = 0
                    matrix[0][c] = 0
                    if r == 0:
                        firstRowZero = True
                    if c == 0:
                        firstColZero = True
        
        for r in range(1, row):
            if matrix[r][0] == 0:
                for c in range(1, col):
                    matrix[r][c] = 0
                    
        for c in range(1, col):
            if matrix[0][c] == 0:
                for r in range(1, row):
                    matrix[r][c] = 0
                    
        if firstRowZero:
            matrix[0] = [0]*col
        if firstColZero:
            for r in range(row):
                matrix[r][0] = 0