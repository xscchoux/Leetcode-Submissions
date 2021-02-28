class Solution(object):
    def minFlipsMonoIncr(self, S):
        """
        :type S: str
        :rtype: int
        """
# DP1
# Time complexity: O(n)
# Space complexity: O(n)
        n = len(S)
        left = [0]*(n+1)
        right = [0]*(n+1)
        res = float('inf')
        
        for i in range(len(S)):
            if S[i] == '1':
                left[i+1] = left[i]+1
            else:
                left[i+1] = left[i]
        
        for i in range(len(S)-1, -1, -1):
            if S[i] == '0':
                right[i] = right[i+1] + 1
            else:
                right[i] = right[i+1]
        
        for i in range(len(left)):
            res = min(res, left[i]+right[i])
            
        return res
        
# DP2
# Time complexity: O(n)
# Space complexity: O(n)
# dp[i][0] := ans of S[0:i+1] and S[i] = 0
# dp[i][1] := ans of S[0:i+1] and S[i] = 1
        n = len(S)
        dp = [[0]*2 for _ in range(n+1)]
        
        for i in range(1,n+1):
            if S[i-1] == '0':
                dp[i][0] = dp[i-1][0]
                dp[i][1] = min(dp[i-1][0], dp[i-1][1]) + 1
            else:
                dp[i][0] = dp[i-1][0] + 1
                dp[i][1] = min(dp[i-1][1], dp[i-1][0])

        
        return min(dp[n][0], dp[n][1])

# DP2 (optimized)
# Time complexity: O(n)
# Space complexity: O(1)
        
        n = len(S)
        dp0, dp1 = 0, 0
        for i in range(n):
            if S[i] == '0':
                dp1 = min(dp0, dp1) + 1
            else:
                dp1 = min(dp1, dp0)
                dp0 = dp0 + 1
                
        return min(dp0, dp1)
        