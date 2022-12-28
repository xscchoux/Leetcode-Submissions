class Solution:
    def countPartitions(self, nums: List[int], k: int) -> int:
        if sum(nums) < k*2:
            return 0
        
        N = len(nums)
        kMod = 1000000007
        
        dp = [0]*(k+1)
        dp[0] = 1
        
        for num in nums:
            for i in range(k-1, -1, -1):
                if i - num < 0:
                    break
                dp[i] += dp[i-num]
                
        return (pow(2, N, kMod) - 2*sum(dp)%kMod)%kMod