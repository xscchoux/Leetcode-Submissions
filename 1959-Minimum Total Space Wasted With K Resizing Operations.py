class Solution(object):
    def minSpaceWastedKResizing(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
# dp[i][j]: total space wasted from nums[0] to nums[i] after j resizing operations
# Bottom-up DP, O(N*N*k)
        N = len(nums)
        dp = [[float('inf')]*(k+1) for _ in range(N)]
        
        total = 0
        mx = 0
        for i in range(N):
            mx = max(mx, nums[i])
            total += nums[i]
            dp[i][0] = mx*(i+1) - total
        
        
        for i in range(1, N):
            for j in range(1, min(i+1,k+1) ):
                intervalSum = 0
                mx = 0
                for s in range(i, 0, -1):
                    mx = max(nums[s], mx)
                    intervalSum += nums[s]
                    dp[i][j] = min(dp[i][j], dp[s-1][j-1] + mx*(i-s+1) - intervalSum)
                    
        return dp[N-1][k]
            