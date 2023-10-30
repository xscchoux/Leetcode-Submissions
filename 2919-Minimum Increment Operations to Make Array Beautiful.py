class Solution:
    def minIncrementOperations(self, nums: List[int], k: int) -> int:
        # dp[i]: make all subarrays of size 3 beautiful using the first i elements, while set nums[i] >= k
        N = len(nums)
        dp = [float('inf')]*N
        dp[0], dp[1], dp[2] = max(0, k-nums[0]), max(0, k-nums[1]), max(0, k-nums[2])
        
        for i in range(3, N):
            dp[i] = min(dp[i], max(0, k-nums[i]) + min(dp[i-1], dp[i-2], dp[i-3]))

        return min(dp[-3:])