class Solution:
    def validSubarrays(self, nums: List[int]) -> int:
        N = len(nums)
        rightSmaller = [N]*N
        stack = []
        for i in range(len(nums)):
            while stack and nums[i] < nums[stack[-1]]:
                idx = stack.pop()
                rightSmaller[idx] = i
            stack.append(i)
        
        res = 0
        for i in range(N):
            res += rightSmaller[i] - i
        
        return res