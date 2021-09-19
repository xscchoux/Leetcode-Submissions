class Solution(object):
    def findDifferentBinaryString(self, nums):
        """
        :type nums: List[str]
        :rtype: str
        """
        n = len(nums[0])
        
        for candidate in range(1<<n):
            tmp = bin(candidate)[2:].zfill(n)
            if tmp not in nums:
                return tmp