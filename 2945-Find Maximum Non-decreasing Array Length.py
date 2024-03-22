class Solution:
    def findMaximumLength(self, nums: List[int]) -> int:
        # dp[i] >= dp[j], where dp[i] = presum[i] - presum[j-1]
        # length[i] = length[j] + 1

# # O(n^2), TLE
#         N = len(nums)
#         dp = [0]*(N+1)
#         length = [0]*(N+1)
        
#         for i in range(len(nums)):
#             tot = nums[i]
#             for j in range(i, -1, -1):
#                 if tot < dp[j]:
#                     tot += nums[j-1]
#                 else:
#                     break
#             dp[i+1] = tot
#             length[i+1] = length[j] + 1

#         return length[-1]
    
# O(n), monotonic stack
        # dp[i] >= dp[j], where dp[i] = presum[i] - presum[j]
        # Thus, presum[i] >= dp[j] + presum[j]
        # Find largest j that satisfies presum[i] >= dp[j] + presum[j]
        # length[i] = length[j] + 1

# binary search
        preSum = [nums[0]]
        for i in range(1, len(nums)):
            preSum.append(preSum[-1] + nums[i])
            
        N = len(nums)
        dp = [0]*(N)
        dp[0] = nums[0]
        length = [0]*(N)
        length[0] = 1
        stack = [(2*nums[0], 0)]
        
        for i in range(1, len(nums)):
            ind = bisect_right(stack, (preSum[i], float('inf')))
            if ind != 0:
                dp[i] = preSum[i] - preSum[stack[ind-1][1]]
                length[i] = length[stack[ind-1][1]] + 1
            else:
                dp[i] = preSum[i]
                length[i] = 1
            while stack and stack[-1][0] > dp[i] + preSum[i]:
                stack.pop()
            stack.append((dp[i]+preSum[i], i))

        return length[-1]
    
# without binary search
        preSum = [nums[0]]
        for i in range(1, len(nums)):
            preSum.append(preSum[-1] + nums[i])
            
        N = len(nums)
        dp = [0]*(N)
        dp[0] = nums[0]
        length = [0]*(N)
        length[0] = 1
        stack = deque([(2*nums[0], 0, preSum[0])])
        preIdx = -1
        acc = 0
        
        for i in range(1, len(nums)):
            while stack and preSum[i] >= stack[0][0]:
                _, preIdx, acc = stack.popleft()
            if preIdx != -1:
                dp[i] = preSum[i] - acc
                length[i] = length[preIdx] + 1
            else:
                dp[i] = preSum[i]
                length[i] = 1
            while stack and stack[-1][0] > dp[i] + preSum[i]:
                stack.pop()
            stack.append((dp[i]+preSum[i], i, preSum[i]))
        return length[-1]