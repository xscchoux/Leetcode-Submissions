class Solution(object):
    def maxSumMinProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
# find the smaller number on the left side and on the right side
#         preSum = [0]
#         for num in nums:
#             preSum.append(preSum[-1] + num)
        
#         n = len(nums)
#         left, right = [-1]*n, [n]*n
        
#         stack = []
#         for i in range(len(nums)):
#             while stack and nums[i] < nums[stack[-1]]:
#                 index = stack.pop()
#                 right[index] = i
#             stack.append(i)
        
#         stack = []
#         for i in range(len(nums)-1, -1, -1):
#             while stack and nums[i] < nums[stack[-1]]:
#                 index = stack.pop()
#                 left[index] = i
#             stack.append(i)
        
#         res = 0
#         for i in range(len(nums)):
#             if left[i] == -1:
#                 res = max(res, nums[i]*preSum[right[i]])
#             else:
#                 res = max(res, nums[i]*(preSum[right[i]] - preSum[left[i]+1]) )
                
#         return res%1000000007

# concise
        nums.append(-1)
        preSum = collections.defaultdict(int)
        preSum = [0]
        for i in range(len(nums)):
            preSum.append(preSum[-1] + nums[i])
        
        res = 0
        stack = [-1]
        for i in range(len(nums)):
            while stack[-1] != -1 and stack and nums[i] < nums[stack[-1]]:
                index = stack.pop()
                res = max(res, nums[index]*(preSum[i] - preSum[stack[-1]+1]))
            stack.append(i)
                
        return res%1000000007