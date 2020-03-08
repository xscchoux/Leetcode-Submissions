class Solution(object):
    def minCostClimbingStairs(self, cost):
        """
        :type cost: List[int]
        :rtype: int
        """
# dp[n] = min(dp[n-1],dp[n-2]) + cost[n]

        res = 0
        dp = [0]*len(cost)
        dp = [0]*2+dp+[0]
        cost = cost + [0]
        for i in range(2, 2+len(cost)):
            dp[i] = min(dp[i-1],dp[i-2]) + cost[i-2]
        
        return dp[-1]