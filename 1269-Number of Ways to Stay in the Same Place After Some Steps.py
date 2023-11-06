class Solution:
    def numWays(self, steps: int, arrLen: int) -> int:
        # dp[steps taken][current position] = ways to come to this state
        arrLen = min(arrLen, steps+1)
        dp = [ [0]*arrLen for _ in range(steps+1) ]
        dp[0][0] = 1
        kMod = 10**9+7
        
        for step in range(1, steps+1):
            for pos in range(arrLen):
                for move in range(-1, 2):
                    if 0 <= pos + move < arrLen:
                        dp[step][pos+move] = (dp[step][pos+move] + dp[step-1][pos])%kMod
                        
        return dp[steps][0]%kMod