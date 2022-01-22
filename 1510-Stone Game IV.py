class Solution(object):
    def winnerSquareGame(self, n):
        """
        :type n: int
        :rtype: bool
        """
        memo = dict()
        
        def dfs(remain):
            if remain == 0:
                return False
            
            if remain in memo:
                return memo[remain]
            
            for k in range(int(remain**0.5), 0, -1):
                if not dfs(remain-k*k):
                    memo[remain] = True
                    return True
                
            memo[remain] = False
            return False
        
        return dfs(n)