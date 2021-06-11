class Solution(object):
    def maxResult(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
# monotone stack
        stack = collections.deque([0])
    
        for i in range(1, len(nums)):
            if i - k > stack[0]:
                stack.popleft()
            nums[i] += nums[stack[0]]
            while stack and nums[i] > nums[stack[-1]]:
                stack.pop()
            stack.append(i)

        return nums[-1]