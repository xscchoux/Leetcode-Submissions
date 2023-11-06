class Solution:
    def lengthOfLongestSubsequence(self, nums: List[int], target: int) -> int:
        # 0-1 knapsack
        N = len(nums)
        dp = [0]*(target+1)
        dp[0] = 0
        
        for i in range(len(nums)):
            for j in range(target, 0, -1):
                if j-nums[i] >= 0:
                    if dp[j-nums[i]] or j - nums[i] == 0:
                        dp[j] = max(dp[j], dp[j-nums[i]] + 1)
        
        return dp[-1] if dp[-1] > 0 else -1