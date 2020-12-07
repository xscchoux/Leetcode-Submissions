class Solution(object):
    def generateMatrix(self, n):
        """
        :type n: int
        :rtype: List[List[int]]
        """
        res = [[0]*n for _ in range(n)]
        left, right, up, down = 0, n-1, 0, n-1
        count = 1
        while True:
            for c in range(left, right+1):
                res[up][c] = count
                count += 1
            up += 1
            if up > down:
                break

            for u in range(up, down+1):
                res[u][right] = count
                count += 1
            right -= 1
            if right < left:
                break
                
            for r in range(right, left-1, -1):
                res[down][r] = count
                count += 1
            down -= 1
            if down < up:
                break
                
            for d in range(down, up-1, -1):
                res[d][left] = count
                count += 1
            left += 1
            if left > right:
                break
        return res