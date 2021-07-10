class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        one = two = 0
        
        for num in nums:
            two |= (one&num)
            one = one^num
            three = one&two
            two = two&(~three)
            one = one&(~three)
        
        return one