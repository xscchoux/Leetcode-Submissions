class Solution(object):
    def wiggleSort(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
# my naive solution

#         N = len(nums)

#         mid = (N-1)//2
#         nums.sort()
#         res = [nums[mid]]
#         m = 1
        
#         while True:
#             if mid + m <N:
#                 res.append(nums[mid+m])
#             else:
#                 break
                
#             if mid - m >= 0:
#                 res.append(nums[mid-m])
#             else:
#                 break
#             m += 1
#         nums[:] = res

# -----------------------------------------------------------------------

# for even indexes, swap nums[i] with nums[i+1] if nums[i] > nums[i+1]
# for odd indexes, swap nums[i] with nums[i+1] if nums[i] < nums[i+1]

        for i in range(len(nums)-1):
            if i%2^(nums[i] > nums[i+1]):
                nums[i], nums[i+1] = nums[i+1], nums[i]