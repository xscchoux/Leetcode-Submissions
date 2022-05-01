class Solution(object):
    def countUnguarded(self, m, n, guards, walls):
        """
        :type m: int
        :type n: int
        :type guards: List[List[int]]
        :type walls: List[List[int]]
        :rtype: int
        """
        grid = [[0]*n for _ in range(m)]
        res = m*n
        
        for u, v in guards+walls:
            grid[u][v] = 1
            res -= 1
                    
        for currR, currC in guards:
            for dr, dc in ((1, 0), (0, 1), (-1, 0), (0, -1)):
                r, c = currR, currC
                while 0 <= r+dr < m and 0 <= c+dc < n and grid[r+dr][c+dc] != 1:
                    r, c = r+dr, c+dc
                    if not grid[r][c]:
                        res -= 1
                        grid[r][c] = 2
        return res