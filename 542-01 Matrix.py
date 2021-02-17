from collections import deque
class Solution(object):
    def updateMatrix(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[List[int]]
        """
        row = len(matrix)
        col = len(matrix[0])
        
        queue = deque()
        
        for r in range(row):
            for c in range(col):
                if matrix[r][c] == 1:
                    matrix[r][c] = float('inf')
                else:
                    queue.append((r,c))
        
        while queue:
            currR, currC = queue.popleft()
            for dr, dc in ((1,0),(0,1),(-1,0),(0,-1)):
                newR = currR + dr
                newC = currC + dc
                if 0<=newR<row and 0<=newC<col and matrix[currR][currC] + 1 < matrix[newR][newC]:
                    matrix[newR][newC] = matrix[currR][currC] + 1
                    queue.append((newR,newC))
        
        return matrix