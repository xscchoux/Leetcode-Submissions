class Solution(object):
    def maximumSubarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        using = collections.defaultdict(int)
        res = 0
        left = 0
        curr = 0
        
        for j in range(len(nums)):
            if j >= k:
                curr -= nums[j-k]
                using[nums[j-k]] -= 1
            if using[nums[j-k]] == 0:
                del using[nums[j-k]]
            
            curr += nums[j]
            using[nums[j]] += 1
            if len(using) == k:
                res = max(res, curr)        
        return res
