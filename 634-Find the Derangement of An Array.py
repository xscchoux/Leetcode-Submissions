class Solution:
    def findDerangement(self, n: int) -> int:
# dp(n) = (n-1)*(dp(n-1)+dp(n-2))
# RecursionError: maximum recursion depth exceeded
#         kMod = 1000000007
        
#         @cache
#         def dp(n):
#             if n == 0:
#                 return 1
#             elif n == 1:
#                 return 0
#             else:
#                 memo[n] = (n-1)*(dp(n-2) + dp(n-1))%kMod
#                 return memo[n]
#         return dp(n)

        kMod = 1000000007
        
        dp = [0]*(n+1)
        dp[0] = 1
        dp[1] = 0
        for i in range(2, n+1):
            dp[i] = (i-1)*(dp[i-1]+dp[i-2])%kMod
            
        return dp[n]