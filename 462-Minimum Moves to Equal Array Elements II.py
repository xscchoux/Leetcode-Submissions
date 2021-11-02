class Solution(object):
    def minMoves2(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
# quick select (find median using quick select) (TLE)

#         def partition(left, right):
#             pivotVal = nums[right]
#             i = left
#             for j in range(left, right+1):
#                 if nums[j] < pivotVal:
#                     nums[i], nums[j] = nums[j], nums[i]
#                     i += 1
#             nums[right], nums[i] = nums[i], nums[right]
#             return i
    
#         def quickSelect(left, right, medianIdx):
#             if left == right:
#                 return nums[left]
#             pivotIdx = partition(left, right)
#             if pivotIdx == medianIdx:
#                 return nums[pivotIdx]
#             elif pivotIdx < medianIdx:
#                 return quickSelect(pivotIdx+1, right, medianIdx)
#             else:
#                 return quickSelect(left, pivotIdx-1, medianIdx)
        
        
#         median = quickSelect(0, len(nums)-1, len(nums)//2)
#         tot = 0
#         for num in nums:
#             tot += abs(median-num)
            
#         return tot
    
# sorting
        nums.sort()
        
        index = len(nums)//2
        res = 0
        
        for i in range(len(nums)):
            res += abs(nums[i]-nums[index])
            
        return res