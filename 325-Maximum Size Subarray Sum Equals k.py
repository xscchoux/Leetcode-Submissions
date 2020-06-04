class Solution(object):
    def maxSubArrayLen(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        prefix = {0:-1}
        _sum = 0
        res = 0
        for i in range(len(nums)):
            _sum += nums[i]
            if _sum-k in prefix:
                res = max(res, i-prefix[_sum-k])
            if _sum not in prefix:
                prefix[_sum] = i
            
        return res