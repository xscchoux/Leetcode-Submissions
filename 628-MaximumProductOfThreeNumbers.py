class Solution(object):
    def maximumProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
# time complexity: O(nlogn)
#         nums.sort()
    
#         return max(nums[-1]*nums[-2]*nums[-3], nums[-1]*nums[0]*nums[1])
    
    
# time complexity: O(n)
        max1 = float('-inf')
        max2 = float('-inf')
        max3 = float('-inf')
        min1 = float('inf')
        min2 = float('inf')
        
        for num in nums:
            if num > max1:
                max3 = max2
                max2 = max1
                max1 = num
            elif num > max2:
                max3 = max2
                max2 = num
            elif num > max3:
                max3 = num
                
            if num<min1:
                min2 = min1
                min1 = num
            elif num<min2:
                min2 = num
                
        return max(max1*max2*max3, max1*min1*min2)