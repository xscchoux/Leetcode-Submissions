class Solution(object):
    def arrayNesting(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        memo = dict()
        res = 1
        
        def dfs(index, head):
            if nums[index] == head:
                return 0
            if nums[index] in memo:
                return memo[nums[index]]
            memo[nums[index]] = 1 + dfs(nums[index], head)
            return memo[nums[index]]           
        
        for i in range(len(nums)):
            if nums[i] not in memo:
                memo[nums[i]] = 1 + dfs(nums[i], nums[i])
                res = max(res, memo[nums[i]])
                
        return res