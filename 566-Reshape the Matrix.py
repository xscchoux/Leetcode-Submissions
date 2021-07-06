class Solution(object):
    def matrixReshape(self, mat, r, c):
        """
        :type mat: List[List[int]]
        :type r: int
        :type c: int
        :rtype: List[List[int]]
        """
        rowNum = len(mat)
        colNum = len(mat[0])
        if (rowNum == r and colNum == c) or r*c != rowNum*colNum:
            return mat
        
        res = [[]]
        
        for row in range(rowNum):
            for col in range(colNum):
                res[-1].append(mat[row][col])
                count = row*(colNum) + col + 1
                if count%c == 0:
                    r-=1
                    if r:
                        res.append([])
        return res