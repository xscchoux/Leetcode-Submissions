class Solution(object):
    def maxPoints(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        row = len(points)
        col = len(points[0])
        prev = points[0]
        
        def leftMax(arr):
            left = [arr[0]] + [0]*(col-1)
            for i in range(1, col):
                left[i] = max(left[i-1]-1, arr[i])
            return left
        
        def rightMax(arr):
            right = [0]*(col-1) + [arr[-1]]
            for i in range(len(arr)-2, -1, -1):
                right[i] = max(right[i+1]-1, arr[i])
            return right
        
        for r in range(1, row):
            leftArr, rightArr = leftMax(prev), rightMax(prev)
            curr = [0]*col
            for c in range(col):
                curr[c] = points[r][c] + max(leftArr[c], rightArr[c])
            prev = curr[:]

        return max(prev)