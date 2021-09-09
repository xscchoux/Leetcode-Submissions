class Solution(object):
    def orderOfLargestPlusSign(self, n, mines):
        """
        :type n: int
        :type mines: List[List[int]]
        :rtype: int
        """
        banned = {tuple(mine) for mine in mines}
        dp = [[0]*n for _ in range(n)]
        res = 0
        
        for r in range(n):
            
            count = 0
            for c in range(n):
                if (r, c) not in banned:
                    count += 1
                else:
                    count = 0
                dp[r][c] = count
            
            count = 0
            for c in range(n-1, -1, -1):
                if (r, c) not in banned:
                    count += 1
                else:
                    count = 0
                dp[r][c] = min(dp[r][c], count)
                
        
        for c in range(n):
            count = 0
            for r in range(n):
                if (r, c) not in banned:
                    count += 1
                else:
                    count = 0
                dp[r][c] = min(dp[r][c], count)
            
            count = 0
            for r in range(n-1,-1,-1):
                if (r, c) not in banned:
                    count += 1
                else:
                    count = 0
                dp[r][c] = min(dp[r][c], count)
                res = max(res, dp[r][c])
                
        return res