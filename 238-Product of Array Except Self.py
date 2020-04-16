class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """

# O(n)
        tmp = 1
        res = []
        for i in range(len(nums)):
            res.append(tmp)
            tmp = tmp*nums[i]
        
        tmp2 = 1
        for j in range(len(nums)-1,-1,-1):
            res[j] = res[j]*tmp2
            tmp2 = tmp2*nums[j]        
        return res