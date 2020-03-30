class Solution(object):
    def stoneGame(self, piles):
        """
        :type piles: List[int]
        :rtype: bool
        """
# dfs + memo
        left, right = 0, len(piles)-1
        memo = {}
        def dfs(left, right):
            if (left, right) in memo:
                return memo[(left, right)]
            if left == right:
                return piles[left]
            memo[(left, right)] = max(piles[left] - dfs(left+1, right) , piles[right] - dfs(left, right-1) )
            return memo[(left, right)]
        
        return dfs(left, right) > 0
    
# dp    
        n = len(piles)
        dp = [[0]*n for _ in range(n)]
        for i in range(n):
            dp[i][i] = piles[i]
            
        for l in range(2, n+1):
            for i in range(n-l+1):
                j = i+l-1
                dp[i][j] = max( piles[i]+dp[i+1][j], piles[j]+dp[i][j-1] )
                
        return dp[0][n-1]