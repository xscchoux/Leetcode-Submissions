class Solution(object):
    def subsetsWithDup(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums.sort()
        res = []
        n = len(nums)
        def dfs(val, start):
            res.append(val)
            for i in range(start, n):
                if i>start and nums[i] == nums[i-1]:
                    continue
                dfs(val+[nums[i]], i+1)
                
        dfs([],0)
        return res