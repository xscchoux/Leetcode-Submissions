class Solution(object):
    def findMaxAverage(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: float
        """

# sliding window 
# time complexity: O(n)
        _sum = 0
        for i in range(k):
            _sum += nums[i]
        res = _sum
        for j in range(k, len(nums)):
            _sum = _sum + nums[j] - nums[j-k]
            if _sum > res:
                res = _sum
            
        return res/float(k)