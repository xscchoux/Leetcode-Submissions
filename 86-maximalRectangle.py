class Solution(object):
    def maximalRectangle(self, matrix):
        """
        :type matrix: List[List[str]]
        :rtype: int
        """
# O(M(N+M)) M:ROWS, N: COLUMNS
        if not matrix or not matrix[0]:
            return 0
        
        def maxArea(height):
            height.append(-1)
            res = 0
            stack = []
            for i in range(len(height)):
                while stack and height[i] < height[stack[-1]]:
                    prevHeightIndex = stack.pop()
                    if not stack:
                        w = i
                    else:
                        w = i - stack[-1] - 1
                    res = max(res, height[prevHeightIndex]*w)
                stack.append(i)
            return res
        
        row = len(matrix)
        col = len(matrix[0])
        height = [0]*col
        res = 0
        for r in range(row):
            for c in range(col):
                if matrix[r][c] == '1':
                    height[c] += 1
                else:
                    height[c] = 0
            res = max(res, maxArea(height))
        
        return res