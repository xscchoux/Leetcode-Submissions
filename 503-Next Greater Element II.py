class Solution(object):
    def nextGreaterElements(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        N = len(nums)
        res = [-1]*N
        stack = []
        
        for i in range(2*len(nums)):
            curr = nums[i%N]
            while stack and curr > nums[stack[-1]]:
                res[stack.pop()] = curr
            if i<N:
                stack.append(i)
        
        return res