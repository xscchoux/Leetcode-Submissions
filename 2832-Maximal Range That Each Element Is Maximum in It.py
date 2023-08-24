class Solution:
    def maximumLengthOfRanges(self, nums: List[int]) -> List[int]:
        
# first try
        N = len(nums)
        res = []
        
        left = [-1]*N
        stack = []
        for i in range(N):
            while stack and nums[i] >= nums[stack[-1]]:
                stack.pop()
            if stack:
                left[i] = stack[-1]
            stack.append(i)
        
        right = [N]*N
        stack = []
        for i in range(N-1, -1, -1):
            while stack and nums[i] >= nums[stack[-1]]:
                stack.pop()
            if stack:
                right[i] = stack[-1]
            stack.append(i)
        
        res = []
        for i in range(N):
            res.append(i-left[i]-1 + right[i]-i-1 + 1)
        
        return res

# one pass

        N = len(nums)
        res = [N]*N
        nums = nums + [float('inf')]
        left = [-1]*N
        stack = []
        for i, val in enumerate(nums):
            while stack and nums[i] >= stack[-1][0]:
                _, idx = stack.pop()
                left = -1 if not stack else stack[-1][1]
                res[idx] = i - left - 1
            stack.append((val, i))
        
        return res