class Solution:
    def tourOfKnight(self, m: int, n: int, r: int, c: int) -> List[List[int]]:
        res = [[-1]*n for _ in range(m)]
        res[r][c] = 0
        
        def dfs(r, c, step):
            if step == m*n:
                return True
            
            for dr, dc in ((1,2),(1,-2),(-1,2),(-1,-2),(2,1),(2,-1),(-2,1),(-2,-1)):
                nxtR = r+dr
                nxtC = c+dc
                if 0<=nxtR<m and 0<=nxtC<n and res[nxtR][nxtC] == -1:
                    res[nxtR][nxtC] = step
                    if dfs(nxtR, nxtC, step+1):
                        return True
                    res[nxtR][nxtC] = -1
            return False
        
        dfs(r, c, 1)
        
        return res
