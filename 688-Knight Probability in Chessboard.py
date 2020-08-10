class Solution(object):
    def knightProbability(self, N, K, r, c):
        """
        :type N: int
        :type K: int
        :type r: int
        :type c: int
        :rtype: float
        """
# https://www.youtube.com/watch?v=MyJvMydR2G4
# time complexity: O(N^2)
# space complexity: O(N^2)
        directions = [(2,1),(1,2),(-1,2),(-2,1),(1,-2),(2,-1),(-1,-2),(-2,-1)]
        dp = [[0]*N for _ in range(N)]
        dp[r][c] = 1
        
        for k in range(K):
            dpNext = [[0]*N for _ in range(N)]
            for oldR in range(N):
                for oldC in range(N):
                    for direction in directions:
                        newR = oldR + direction[0]
                        newC = oldC + direction[1]
                        if newR<0 or newC<0 or newR>=N or newC>=N:
                            continue
                        dpNext[newR][newC] += dp[oldR][oldC]
            dp, dpNext = dpNext, dp
            
        total = 0
        
        for x in range(N):
            for y in range(N):
                total += dp[x][y]
        
        return total/float(8**K)