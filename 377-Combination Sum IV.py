class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        # Bottom-Up DP
        dp = [0]*(target+1)
        dp[0] = 1
        
        for i in range(1, target+1):
            for num in nums:
                if i - num >= 0:
                    dp[i] += dp[i-num]
        
        return dp[-1]
    
        
        # Top-Down DP
        @cache
        def dfs(currVal):
            if currVal == target:
                return 1
            res = 0
            for num in nums:
                if currVal + num <= target:
                    res += dfs(currVal+num)
            
            return res
        
        return dfs(0)