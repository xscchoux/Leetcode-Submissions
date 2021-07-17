# Sol 1
from functools import cmp_to_key 
class Solution(object):
    def largestNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: str
        """
        def customCompare(a,b):
            if a + b > b + a:
                return -1
            else:
                return 1
        
        nums = list(map(str, nums))
        nums.sort(key = cmp_to_key(customCompare))
        
        return "0" if nums[0] == "0" else "".join(nums)

# Sol 2
class customCompare(str):
    def __lt__(a, b):
        return a+b > b+a
    
class Solution(object):
    def largestNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: str
        """
        
        nums = list(map(str, nums))
        nums.sort(key = customCompare)
        
        return "0" if nums[0] == "0" else "".join(nums)