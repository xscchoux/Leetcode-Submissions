class Solution(object):
    def findPaths(self, m, n, maxMove, startRow, startColumn):
        """
        :type m: int
        :type n: int
        :type maxMove: int
        :type startRow: int
        :type startColumn: int
        :rtype: int
        """
        
# Brute force, TLE
#         res = 0
        
#         queue = collections.deque([(startRow,startColumn)])
        
#         for _ in range(maxMove):
#             for _ in range(len(queue)):
#                 r, c = queue.popleft()
#                 for dr, dc in ((1,0),(0,1),(-1,0),(0,-1)):
#                     newR = r + dr
#                     newC = c + dc
#                     if 0<=newR<m and 0<=newC<n:
#                         queue.append((newR, newC))
#                     else:
#                         res += 1
        
#         return res

# DFS + memo, Time:O(m*n*maxMove), Space:O(m*n*maxMove)
        memo = dict()
        kMod = 10**9+7
    
        def dfs(r, c, N):
            if r<0 or r>=m or c<0 or c>=n:
                return 1
            if N == 0:
                return 0
            if (r, c, N) in memo:
                return memo[(r, c, N)]
            res = 0
            res += dfs(r-1, c, N-1) + dfs(r+1, c, N-1) + dfs(r, c+1, N-1) + dfs(r, c-1, N-1)
            memo[(r,c,N)] = res%kMod
            return memo[(r,c,N)]
        
        return dfs(startRow, startColumn, maxMove)
    
    
# dp (hard to come up with), Time:O(m*n*maxMove), Space:O(m*n) 
# dp[i][j]: number of ways the position corresponding to the indices (i,j) can be reached

        kMod = 10**9+7
        dp = [[0]*n for _ in range(m)]
        dp[startRow][startColumn] = 1
        count = 0
        for _ in range(maxMove):
            tmp = [[0]*n for _ in range(m)]
            for r in range(0, m):
                for c in range(0, n):
                    if r == 0:
                        count = (count + dp[r][c])%kMod
                    if c == 0:
                        count = (count + dp[r][c])%kMod
                    if r == m-1:
                        count = (count + dp[r][c])%kMod
                    if c == n-1:
                        count = (count + dp[r][c])%kMod
                    if r>0:
                        tmp[r][c] += dp[r-1][c]
                    if r<m-1:
                        tmp[r][c] += dp[r+1][c]
                    if c>0:
                        tmp[r][c] += dp[r][c-1]
                    if c<n-1:
                        tmp[r][c] += dp[r][c+1]
            dp = tmp
            
        return count