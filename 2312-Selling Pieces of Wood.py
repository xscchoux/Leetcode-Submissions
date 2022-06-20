class Solution(object):
    def sellingWood(self, m, n, prices):
        """
        :type m: int
        :type n: int
        :type prices: List[List[int]]
        :rtype: int
        """
        dp = [[0]*(n+1) for _ in range(m+1)]
        
        for r, c, price in prices:
            dp[r][c] = price
        
        for r in range(1, m+1):
            for c in range(1, n+1):
                for nr in range(1, r//2+1):
                    dp[r][c] = max(dp[r][c], dp[nr][c] + dp[r-nr][c])
                for nc in range(1, c//2+1):
                    dp[r][c] = max(dp[r][c], dp[r][nc] + dp[r][c-nc])
        
        return dp[-1][-1]