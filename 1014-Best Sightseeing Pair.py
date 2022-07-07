class Solution(object):
    def maxScoreSightseeingPair(self, values):
        """
        :type values: List[int]
        :rtype: int
        """
# first try
#         N = len(values)
#         dp = [float('-inf')]*N
#         dp[N-1] = values[N-1]-(N-1)

#         for i in range(N-2, 0, -1):
#             dp[i] = max(values[i]-i, dp[i+1])
        
#         res = float('-inf')
#         for i in range(0, N-1):
#             res = max(res, i+values[i]+dp[i+1])
            
#         return res


# best solution
        N = len(values)
        imax = values[0]
        res = 0
    
        for j in range(1, N):
            res = max(res, imax + values[j] - j)
            imax = max(imax, values[j]+j)
        
        return res