class Solution(object):
    def findDiagonalOrder(self, nums):
        """
        :type nums: List[List[int]]
        :rtype: List[int]
        """
        res = []
        for i in range(len(nums)):
            for j in range(len(nums[i])):
                if i+j >= len(res):
                    res.append([])
                res[i+j].append(nums[i][j])
                
        ans = []
        for i in range(len(res)):
            ans.extend(res[i][::-1])
        return ans