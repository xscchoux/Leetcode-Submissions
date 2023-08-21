class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        N = len(nums)
        # dp[i][curr]: (curr = 0~2 ) min operations to make ith number curr and nums is non-decreasing
        dp = [[float('inf')]*3 for _ in range(N+1)]
        for i in range(3):
            dp[0][i] = 0
        
        for i, num in enumerate(nums):
            for j in range(3):
                if num-1 == j:
                    for prev in range(j+1):
                        dp[i+1][j] = min(dp[i+1][j], dp[i][prev])
                else:
                    for prev in range(j+1):
                        dp[i+1][j] = min(dp[i+1][j], dp[i][prev] + 1)
        
        return min(dp[-1])