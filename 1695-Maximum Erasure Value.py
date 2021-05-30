class Solution(object):
    def maximumUniqueSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        left = 0
        summ = 0
        res = 0
        used = set()
        
        for i in range(len(nums)):
            if nums[i] in used:
                res = max(res, summ)
                while nums[i] in used:
                    used.remove(nums[left])
                    summ -= nums[left]
                    left += 1
            used.add(nums[i])
            summ += nums[i]

        res = max(res, summ)
        
        return res