class Solution(object):
    def countSubranges(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: int
        """
# O(N * 100 * N)
# The size of DP will not exceeded 2 * 100 * N, so So iterate all key-value pair of DP take O(100 * N)
        
        n = len(nums1)
        dp = [collections.defaultdict(int) for _ in range(n)]
        kMod = 1000000007
        res = 0
        
        for i in range(n):
            dp[i][nums1[i]] += 1
            dp[i][-nums2[i]] += 1
            if i>0:
                for key in dp[i-1]:
                    dp[i][key + nums1[i]] += dp[i-1][key]
                    dp[i][key - nums2[i]] += dp[i-1][key]
            
            res = (res + dp[i][0])%kMod
        
        return res