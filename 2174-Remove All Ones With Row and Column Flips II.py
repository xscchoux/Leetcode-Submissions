class Solution(object):
    def removeOnes(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
# O(M*N*2^(MN))
        row, col = len(grid), len(grid[0])
        one = set()
        for r in range(row):
            for c in range(col):
                if grid[r][c] == 1:
                    one.add((r, c))
        self.res = float('inf')
        
        def dfs(ans):
            if not one:
                self.res = min(self.res, ans)
                return 
            for currR, currC in one:
                deleted = set()
                for c in range(col):
                    if (currR, c) in one:
                        one.remove((currR, c))
                        deleted.add((currR, c))
                for r in range(row):
                    if (r, currC) in one:
                        one.remove((r, currC))
                        deleted.add((r, currC))
                dfs(ans + 1)
                for x in deleted:
                    one.add(x)
        dfs(0)
        
        return self.res