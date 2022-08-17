class Solution:
    def countSpecialNumbers(self, n: int) -> int:
        
        @cache
        def A(m, n):
            res = 1
            for i in range(m, m-n, -1):
                res *= i
            return res
        
        s = str(n)
        N = len(s)
        self.ans = 0
        
        for length in range(1, N):
            self.ans += A(10, length) - A(9, length-1)
        visited = [0]*10
        
        def dfs(ind):
            if ind >= N:
                self.ans += 1
                return
            
            for k in range(10):
                if ind == 0 and k == 0:
                    continue
                if visited[k]:
                    continue
                if k < int(s[ind]):
                    self.ans += A(10-ind-1, N-ind-1)
                elif k == int(s[ind]):
                    visited[k] = 1
                    dfs(ind+1)
                    visited[k] = 0
                else:
                    break
        dfs(0)
        return self.ans