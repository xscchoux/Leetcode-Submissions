class Solution(object):
    def shortestSubarray(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
# cannot use sliding window when a list has negative values      
#         def isOK(target):
#             running = 0
#             for i in range(target):
#                 running += nums[i]
#             if running >= k:
#                 return True
#             for i in range(target, len(nums)):
#                 running += nums[i] - nums[i-target]
#                 if running >= k:
#                     return True
#             return False
        
        
#         left, right = 1, len(nums)
        
#         while left + 1 < right:
#             mid = left + (right-left)//2
#             if isOK(mid):
#                 right = mid
#             else:
#                 left = mid
#         print(left, right)
#         if isOK(left):
#             return left
#         elif isOK(right):
#             return right
#         else:
#             return -1


# deque

        N = len(nums)
        res = N+1
        dq = collections.deque([0])
        preSum = [0]
        for num in nums:
            preSum.append(preSum[-1]+num)
        
        for i in range(1, N+1):
            while dq and preSum[i] - preSum[dq[0]] >= k:
                res = min(res, i-dq.popleft())
            while dq and preSum[i] < preSum[dq[-1]]:
                dq.pop()
            dq.append(i)
            
        return [res, -1][res == N+1]