class Solution:
    def maxNonDecreasingLength(self, nums1: List[int], nums2: List[int]) -> int:

# first try
        N = len(nums1)
        dp = [[1]*2 for _ in range(N)]
        res = 1
        
        for i in range(1, N):
            if nums1[i] >= nums1[i-1]:
                dp[i][0] = max(dp[i][0], dp[i-1][0] + 1)
            if nums1[i] >= nums2[i-1]:
                dp[i][0] = max(dp[i][0], dp[i-1][1] + 1)
                
            if nums2[i] >= nums1[i-1]:
                dp[i][1] = max(dp[i][1], dp[i-1][0] + 1)
            if nums2[i] >= nums2[i-1]:
                dp[i][1] = max(dp[i][1], dp[i-1][1] + 1)
            
            res = max(res, dp[i][1], dp[i][0])
        
        return res

# Concise solution
        N = len(nums1)
        res = dp1 = dp2 = 1
        
        for i in range(1, N):
            t11 = dp1 + 1 if nums1[i] >= nums1[i-1] else 1
            t12 = dp1 + 1 if nums2[i] >= nums1[i-1] else 1
            t21 = dp2 + 1 if nums1[i] >= nums2[i-1] else 1
            t22 = dp2 + 1 if nums2[i] >= nums2[i-1] else 1
            dp1 = max(t11, t21)
            dp2 = max(t12, t22)
            res = max(res, dp1, dp2)
            
        return res