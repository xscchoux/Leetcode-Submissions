class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
# O(N) solution, majority problem
# https://www.geeksforgeeks.org/n3-repeated-number-array-o1-space/
        count1, count2 = 0, 0
        num1, num2 = float('inf'), float('inf')
        
        for i in range(len(nums)):
            if nums[i] == num1:
                count1 += 1
            elif nums[i] == num2:
                count2 += 1
            elif count1 == 0:
                num1 = nums[i]
                count1 = 1
            elif count2 == 0:
                num2 = nums[i]
                count2 = 1
            else:
                count1 -= 1
                count2 -= 1
                
        count1, count2 = 0, 0
        for i in range(len(nums)):
            if num1 == nums[i]:
                count1+=1
            elif num2 == nums[i]:
                count2 += 1
        
        res = []
        if count1 > len(nums)//3:
            res.append(num1)
        if count2 > len(nums)//3:
            res.append(num2)
        return res
        