class Solution(object):
    def find132pattern(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
# time complexity: O(n)
# 2 > 3 , 3 > 1
# https://blog.csdn.net/magicbean2/article/details/78531200
        if len(nums) <3:
            return False
        
        n = len(nums)
        
        stack = []
        third = float('-inf')
        for i in range(n-1, -1, -1):
            if nums[i] < third:
                return True
            while stack and nums[i] > stack[-1]:
                third = stack.pop()
            stack.append(nums[i])
        return False