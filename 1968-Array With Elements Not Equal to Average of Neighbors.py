class Solution(object):
    def rearrangeArray(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
# first try
#         N = len(nums)
#         nums.sort()
#         res = [0]*N
#         if N%2:
#             for i in range(0, N//2+1):
#                 res[2*i] = nums[i]
#             j = 1
#             for i in range(N//2+1, N):
#                 res[j] = nums[i]
#                 j+=2
#         else:
#             for i in range(0, N//2):
#                 res[2*i] = nums[i]
#             j = 1
#             for i in range(N//2, N):
#                 res[j] = nums[i]
#                 j += 2
                
#         return res

# O(n)
        for i in range(1, len(nums)-1):
            if (nums[i]>nums[i-1])^(nums[i]>nums[i+1]):
                nums[i], nums[i+1] = nums[i+1], nums[i]
        
        return nums