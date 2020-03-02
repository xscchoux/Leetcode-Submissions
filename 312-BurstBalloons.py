class Solution(object):
    def maxCoins(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums = [1] + nums + [1]
        n = len(nums)
        dp = [[0]*n for _ in range(n)]
        
        for l in range(1, n-1):
            for i in range(1, n-l):
                j = i+l-1
                dp[i][j] = max([dp[i][k-1] + nums[i-1]*nums[k]*nums[j+1] + dp[k+1][j]  for k in range(i, j+1) ])
        return dp[1][n-2]