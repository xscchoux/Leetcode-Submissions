class Solution(object):
    def totalNQueens(self, n):
        """
        :type n: int
        :rtype: int
        """
        
# Time: O(n!), space:O(n^2)

        row = [False]*n
        col = [False]*n
        diag1 = [False]*(2*n-1)
        diag2 = [False]*(2*n-1)
        self.res = 0
        
        def dfs(r):
            if r == n:
                self.res+=1
                return
                
            for c in range(n):
                if not col[c] and not row[r] and not diag1[r+c] and not diag2[r-c+n-1]:
                    row[r] = True
                    col[c] = True
                    diag1[r+c] = True
                    diag2[r-c+n-1] = True
                    dfs(r+1)
                    row[r] = False
                    col[c] = False
                    diag1[r+c] = False
                    diag2[r-c+n-1] = False
                
        dfs(0)
        return self.res