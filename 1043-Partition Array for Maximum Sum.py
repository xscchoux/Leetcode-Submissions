class Solution(object):
    def maxSumAfterPartitioning(self, arr, k):
        """
        :type arr: List[int]
        :type k: int
        :rtype: int
        """
        N = len(arr)
        dp = [0]*(N+1)
        
        for i in range(N):
            currMax = arr[i]
            limit = min(k, i+1)
            for j in range(limit):
                currMax = max(currMax, arr[i-j])
                dp[i+1] = max(dp[i+1], dp[i-j] + currMax*(j+1) )
        return dp[-1]