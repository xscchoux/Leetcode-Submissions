class Solution(object):
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        if not matrix or not matrix[0]:
            return []
        
        row = len(matrix)
        col = len(matrix[0])

        left, right, up, down = 0, col-1, 0, row-1
        res = []
        while True:
            if left<=right:
                for i in range(left, right+1):
                    res.append(matrix[up][i])
            else:
                break
            
            up+=1
            
            if up <= down:
                for i in range(up,down+1):
                    res.append(matrix[i][right])
            else:
                break
                
            right-=1
            
            if left <= right:
                for i in range(right, left-1, -1):
                    res.append(matrix[down][i])
            else:
                break
                
            down-=1
            
            if up<=down:
                for i in range(down, up-1,-1):
                    res.append(matrix[i][left])
            else:
                break
                
            left += 1
                
        return res