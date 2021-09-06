class Solution(object):
    def firstDayBeenInAllRooms(self, nextVisit):
        """
        :type nextVisit: List[int]
        :rtype: int
        """
# https://www.youtube.com/watch?v=GYyHxkGO4J0
# dp[i]: the number of days required to visit the ith room for the first time
        kMod = 1000000007
        N = len(nextVisit)
        dp = [0]*N
        
        for i in range(1, N):
            nxt = nextVisit[i-1]
            dp[i] = (dp[i-1] + 2 + (dp[i-1] - dp[nxt]))%kMod
        
        return dp[-1]