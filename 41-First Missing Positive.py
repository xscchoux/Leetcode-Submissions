class Solution(object):
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
# Sol 1
# https://www.youtube.com/watch?v=8DqewGsVNkI&ab_channel=basketwangCoding
        for i in range(len(nums)):
            if nums[i] <= 0:
                nums[i] = float('inf')
        
        for i in range(len(nums)):
            if abs(nums[i]) > 0 and abs(nums[i]) <= len(nums):
                curr = abs(nums[i])
                nums[curr-1] = (-1)*abs(nums[curr-1])
                
        for i in range(len(nums)):
            if nums[i] > 0:
                return i+1
        
        return len(nums)+1
        

# Sol2
# https://www.youtube.com/watch?v=cG1rZPIo3ww&t=437s&ab_channel=%E5%82%85%E7%A0%81%E7%88%B7
        for i in range(len(nums)):
            while nums[i] > 0 and nums[i] <= len(nums) and nums[i] != nums[nums[i]-1]:
                tmp = nums[nums[i]-1]
                nums[nums[i]-1] = nums[i]
                nums[i] = tmp
                
# Don't use nums[i], nums[nums[i]-1] = nums[nums[i]-1], nums[i]
# nums[i] will be modified first and then affect the second variable nums[nums[i] - 1].
        
        for i in range(len(nums)):
            if nums[i]-1 != i:
                return i+1
        
        return len(nums) + 1