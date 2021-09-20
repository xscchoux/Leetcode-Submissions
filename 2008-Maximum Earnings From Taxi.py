class Solution(object):
    def maxTaxiEarnings(self, n, rides):
        """
        :type n: int
        :type rides: List[List[int]]
        :rtype: int
        """
        dp = [0]*(n+1)
        Nride = len(rides)
        idx = 0
        rides.sort(key = lambda x: x[1])
        
        for i in range(1, n+1):
            if rides[idx][1] == i:
                dp[i] = dp[i-1]
                while idx < Nride and rides[idx][1] == i:
                    dp[i] = max(dp[i], dp[rides[idx][0]]+rides[idx][1]-rides[idx][0]+rides[idx][2])
                    idx+=1
                if idx == Nride:
                    return dp[i]
            else:
                dp[i] = dp[i-1]