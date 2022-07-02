class Solution(object):
    def findMaximums(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        N = len(nums)
        left = [-1]*N
        right = [N]*N
        
        stack = []
        for i in range(N):
            while stack and nums[i] < nums[stack[-1]]:
                ind = stack.pop()
                right[ind] = i
            if stack:
                left[i] = stack[-1]
            stack.append(i)
        
        res = [0]*N
        for idx in range(N):
            length = right[idx]-left[idx]-1
            res[length-1] = max(nums[idx], res[length-1])
        
        for i in range(N-2, -1, -1):
            res[i] = max(res[i], res[i+1])
        
        return res