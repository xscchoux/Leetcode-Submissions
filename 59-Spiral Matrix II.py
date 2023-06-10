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
            
            for r in range(up, down+1):
                res[r][right] = count
                count += 1
            right -= 1
            if right < left:
                break
                
            for c in range(right, left-1, -1):
                res[down][c] = count
                count += 1
            down -= 1
            if down < up:
                break
                
            for r in range(down, up-1, -1):
                res[r][left] = count
                count += 1
            left += 1
            if left > right:
                break
                
        return res

# Better
        res = [[0]*n for _ in range(n)]
        count = 1
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        r = c = 0
        d = 0
        
        while count <= n*n:
            res[r][c] = count
            count += 1
            nxtR, nxtC = r + directions[d][0], c + directions[d][1]
            if nxtR < 0 or nxtR == n or nxtC < 0 or nxtC == n or res[nxtR][nxtC] != 0:
                d = (d+1)%4
            r += directions[d][0]
            c += directions[d][1]

        return res