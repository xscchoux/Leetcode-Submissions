class Solution:
    def maximizeWin(self, prizePositions: List[int], k: int) -> int:      
# O(n) DP
        N = len(prizePositions)
        dp1 = [0]*(N+1)
        left = 0
        
        for i in range(N):
            while prizePositions[i] - prizePositions[left] > k:
                left += 1
            dp1[i+1] = max(dp1[i], i-left+1)
        
        dp2 = [0]*(N+1)
        right = N-1
        for i in range(N-1, -1, -1):
            while prizePositions[right] - prizePositions[i] > k:
                right -= 1
            dp2[i] = max(dp2[i+1], right-i+1)
        
        res = 0
        for i in range(N+1):
            res = max(res, dp1[i]+dp2[i])
        
        return res
    
# optimized DP
        N = len(prizePositions)
        dp = [0]*(N+1)
        left = res = j = 0
        
        for i in range(N):
            while prizePositions[i] - prizePositions[j] > k:
                j += 1
            dp[i+1] = max(dp[i], i-j+1)
            res = max(res, i-j+1 + dp[j])
        
        return res