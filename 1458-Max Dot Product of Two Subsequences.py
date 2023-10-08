class Solution:
    def maxDotProduct(self, nums1: List[int], nums2: List[int]) -> int:
        # dp[i][j] : max product of nums1[:i+1], nums2[:j+1]
        # dp[i][j] = max(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]+nums1[i]*nums2[j])
        
        N1, N2 = len(nums1), len(nums2)
        dp = [[0]*(N2+1) for _ in range((N1+1))]
        
        for i in range(1, N1+1):
            for j in range(1, N2+1):
                dp[i][j] = max(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]+nums1[i-1]*nums2[j-1])

        if dp[N1][N2] > 0:
            return dp[N1][N2]
        else:
            m1 = sorted(nums1, key = lambda x:abs(x))[0]
            m2 = sorted(nums2, key = lambda x:abs(x))[0]
            return m1*m2