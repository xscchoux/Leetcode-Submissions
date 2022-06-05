class Solution:
    def minDifficulty(self, jobDifficulty: List[int], d: int) -> int:
        if len(jobDifficulty) < d:
            return -1
        N = len(jobDifficulty)
        
        @cache
        def dfs(startIdx, d):
            if d == 1:
                return max(jobDifficulty[startIdx:])
            
            mx = 0
            res = float('inf')
            for i in range(startIdx, N):
                if i == N - d + 1:
                    break
                mx = max(mx, jobDifficulty[i])
                res = min(res, mx + dfs(i+1, d-1) )
                
            return res
        
        return dfs(0, d)