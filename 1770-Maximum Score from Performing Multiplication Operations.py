class Solution:
    def maximumScore(self, nums: List[int], multipliers: List[int]) -> int:
        
# Top-down, TLE
        m, n = len(multipliers), len(nums)
        left = 0
        
        @cache
        def dfs(ind, left):
            if ind == m:
                return 0
            
            return max(multipliers[ind]*nums[left] + dfs(ind+1, left+1), multipliers[ind]*nums[left+n-1-ind] + dfs(ind+1, left))
            
            # return res
        
        return dfs(0, 0)
    
    
# barely pass, dp[op][left] 
# op: total operations - 1
# left: the start of arr
        m, n = len(multipliers), len(nums)
        dp = [[0]*(m+1) for _ in range(m+1)]
        
        for op in range(m-1, -1, -1):
            for left in range(op, -1, -1):
                dp[op][left] = max(multipliers[op]*nums[left] + dp[op+1][left+1], multipliers[op]*nums[n-1-(op-left)] + dp[op+1][left])
                
        return dp[0][0]
    
# optimal solution
        m, n = len(multipliers), len(nums)
        dp = [0]*(m+1)
        
        for op in range(m-1, -1, -1):
            prev = dp[:]
            for left in range(op, -1, -1):
                dp[left] = max(multipliers[op]*nums[left] + prev[left+1], multipliers[op]*nums[n-1-(op-left)] + prev[left])
                
        return dp[0]