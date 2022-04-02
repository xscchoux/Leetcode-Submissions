class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        row, col = len(matrix), len(matrix[0])
        currR, currC = len(matrix)-1, 0
        
        while 0<=currR<row and 0<=currC<col:
            if matrix[currR][currC] == target:
                return True
            elif matrix[currR][currC] > target:
                currR -= 1
            else:
                currC += 1
        
        return False