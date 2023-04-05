class Solution(object):
    def minimizeArrayValue(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        mx = 0
        curr = 0
        
        for i in range(len(nums)):
            curr += nums[i]
            mx = max(mx, (curr+i)//(i+1))
            
        return mx


# walrus operator
class Solution:
    def minimizeArrayValue(self, nums: List[int]) -> int:
        res = tot = 0
        
        for i in range(len(nums)):
            tot += nums[i]
            if (x:=math.ceil(tot/(i+1))) > res:
                res = x
        
        return res