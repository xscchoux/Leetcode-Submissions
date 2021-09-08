class Solution(object):
    def smallestRangeII(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
# O(NlogN)
# https://jimmy-shen.medium.com/an-interesting-problem-910-smallest-range-ii-302ca119bc8c
        nums.sort()
        n = len(nums)
        res = nums[n-1] - nums[0]
        
        for i in range(n-1):
            mx = max(nums[i]+k, nums[n-1]-k)
            mn = min(nums[0]+k, nums[i+1]-k)
            res = min(res, mx-mn)
            
        return res