class Solution(object):
    def findFarmland(self, land):
        """
        :type land: List[List[int]]
        :rtype: List[List[int]]
        """
        row = len(land)
        col = len(land[0])
        
        res = []
        
        def dfs(r, c):
            land[r][c] = 0
            maxr, maxc = r, c
            for dr, dc in ((1,0),(0,1),(-1,0),(0,-1)):
                nr = r+dr
                nc = c+dc
                if 0<=nr<row and 0<=nc<col and land[nr][nc] == 1:
                    rr, cc = dfs(nr, nc)
                    maxr = max(r, rr)
                    maxc = max(c, cc)
                
            return maxr, maxc
        
        
        for r in range(row):
            for c in range(col):
                if land[r][c] == 1:
                    nr,nc = dfs(r, c)
                    res.append([r, c, nr, nc])
                    
        return res