class Solution(object):
    def minimumFinishTime(self, tires, changeTime, numLaps):
        """
        :type tires: List[List[int]]
        :type changeTime: int
        :type numLaps: int
        :rtype: int
        """
# https://leetcode.com/problems/minimum-time-to-finish-the-race/discuss/1802444/C%2B%2B-Linear-time-DP-with-explanation
        consecutivelap = [float('inf')]*18
        consecutivelap[0] = 0
        
        for f, r in tires:
            toAdd = prefix = f
            for lap in range(1, 18):
                consecutivelap[lap] = min(consecutivelap[lap], prefix)
                toAdd *= r
                if toAdd > changeTime + f:
                    break
                prefix += toAdd
                
        memo = collections.defaultdict(int)
        
        def dp(totlaps):
            if totlaps in memo:
                return memo[totlaps]
            res = float('inf')
            for j in range(1, min(totlaps, 17)+1):
                if totlaps == j:
                    res = min(res, consecutivelap[j])
                else:
                    res = min(res, dp(totlaps-j) + changeTime + consecutivelap[j])
            memo[totlaps] = res
            return res
        
        return dp(numLaps)