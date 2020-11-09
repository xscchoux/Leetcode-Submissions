from collections import deque
class Solution(object):
    def maxSlidingWindow(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        stack = deque()
        res = []
        
        for i in range(len(nums)):
            while stack and nums[i] > nums[stack[-1]]:
                stack.pop()
            stack.append(i)
            if i < k-1:
                continue
            if i - stack[0] == k:
                stack.popleft()
            res.append(nums[stack[0]])
        
        return res