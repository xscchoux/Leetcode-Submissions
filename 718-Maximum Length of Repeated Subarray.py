class Solution(object):
    def findLength(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: int
        """
        n1, n2 = len(nums1), len(nums2)
        
        dp = [[0]*(n1+1) for _ in range(n2+1)]
        res = 0
        
        for r in range(1, n2+1):
            for c in range(1, n1+1):
                if nums1[c-1] == nums2[r-1]:
                    dp[r][c] = dp[r-1][c-1] + 1
                    res = max(dp[r][c], res)
                    
        return res