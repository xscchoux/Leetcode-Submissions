class Solution:
    def maxIncreasingSubarrays(self, nums: List[int]) -> int:
        N = len(nums)
        dp = [1]*N
        for i in range(1, N):
            if nums[i] > nums[i-1]:
                dp[i] += dp[i-1]
        
        res = 0
        # case 1, two adjacent subarrays
        for i in range(1, N):
            if i - dp[i] >= 0 and dp[i-dp[i]] >= dp[i]:
                res = max(res, dp[i])
        
        # case 2, same subarray
        for i in range(1, N):
            if dp[i]%2:
                res = max(res, (dp[i]-1)//2 )
            else:
                res = max(res, dp[i]//2)

        return res