class Solution(object):
    def mincostTickets(self, days, costs):
        """
        :type days: List[int]
        :type costs: List[int]
        :rtype: int
        """
# naive O(n^2) approach
#         N = len(days)
#         dp = [0]*(N+1)
#         minCost = min(costs)
        
#         for i in range(N):
#             dp[i+1] = dp[i] + minCost
#             for j in range(i):
#                 diff = days[i] - days[j]
                
#                 if diff < 7:
#                     dp[i+1] = min(dp[i+1], dp[j] + costs[1])
#                 elif diff == 7:
#                     dp[i+1] = min(dp[i+1], dp[j+1] + costs[1])

                
#                 if diff < 30:
#                     dp[i+1] = min(dp[i+1], dp[j] + costs[2])
#                 elif diff == 30:
#                     dp[i+1] = min(dp[i+1], dp[j+1] + costs[2])

#         return dp[-1]
    
# Top-down DP, O(N)
# dp(i): minimum cost after the ith element
        N = len(days)
        passDay = [1,7,30]
        memo = dict()
    
        def dp(i):
            if i>=N:
                return 0
            if i in memo:
                return memo[i]
            
            res = float('inf')
            nxtIdx = i
            
            for d, cost in zip(passDay, costs):
                while nxtIdx < N and days[nxtIdx] < days[i] + d:
                    nxtIdx += 1
                res = min(res, cost + dp(nxtIdx) )
            
            memo[i] = res
            return res
        
        return dp(0)