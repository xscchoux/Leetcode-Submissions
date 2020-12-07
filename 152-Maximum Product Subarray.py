class Solution(object):
    def maxProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        maxByFar = nums[0]
        minByFar = nums[0]
        res = nums[0]
        
        for i in range(1, len(nums)):
            if nums[i] > 0:
                maxByFar = max(nums[i], maxByFar*nums[i])
                minByFar = min(nums[i], minByFar*nums[i])
            else:
                tmp = maxByFar
                maxByFar = max(minByFar*nums[i], nums[i])
                minByFar = min(tmp*nums[i], nums[i])
            res = max(maxByFar, res)
        
        return res