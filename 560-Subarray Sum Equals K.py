class Solution(object):
    def subarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
# https://www.youtube.com/watch?v=mKXIH9GnhgU&t=201s
# https://blog.csdn.net/fuxuemingzhu/article/details/82767119

        dp = dict()
        dp[0] = 1
        res = 0
        _sum = 0
        for num in nums:
            _sum += num
            if _sum - k in dp:
                res += dp[_sum-k]
            dp[_sum] = dp.get(_sum, 0) + 1
        
        return res