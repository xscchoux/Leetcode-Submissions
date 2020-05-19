class Solution(object):
    def findDiagonalOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        if not matrix or not matrix[0]:
            return []
        
        M = len(matrix[0])
        N = len(matrix)
        res = []
        intermediate = []
        
        for row in range(N+M-1):
            intermediate = []
            if row < M:
                r = 0
            else:
                r = row - M + 1
            
            if row < M:
                c = row
            else:
                c = M-1
                
            while r < N and c >= 0:
                intermediate.append(matrix[r][c])
                r += 1
                c-= 1
            if row%2 == 1:
                res+=intermediate
            else:
                res+=intermediate[::-1]
            
        return res
                