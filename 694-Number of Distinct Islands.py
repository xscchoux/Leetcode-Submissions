class Solution(object):
    def numDistinctIslands(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        if not grid or not grid[0]:
            return 0
        row = len(grid)
        col = len(grid[0])
        visited = set()
        res = set()
        
        def dfs(r0, c0, r, c, string):
            for dr, dc in ((0,1),(1,0),(-1,0),(0,-1)):
                newr = r + dr
                newc = c + dc
                if 0<=newr<row and 0<=newc<col and grid[newr][newc] == 1 and (newr, newc) not in visited:
                    visited.add((newr, newc))
                    string.append(str(newr-r0)+str(newc-c0))
                    dfs(r0, c0, newr, newc, string)
                    
        
        for r in range(row):
            for c in range(col):
                if grid[r][c] == 1 and (r, c) not in visited:
                    visited.add((r,c))
                    string = ['00']
                    dfs(r, c, r, c, string)
                    res.add("_".join(string))
        # print(res)
        return len(res)