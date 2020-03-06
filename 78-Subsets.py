class Solution(object):
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
# DFS O(N*2^N)
        res = []
        n = len(nums)
        def dfs(val,start):
            res.append(val)
            for i in range(start,n):
                dfs(val+[nums[i]], i+1)
        dfs([],0)
        return res
            