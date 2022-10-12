class Solution(object):
    def minimumSplits(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def computeGCD(x, y):
            while y:
                x, y = y, x % y
            return abs(x)
        
        count = 0
        gcd = 1
        
        for num in nums:
            gcd = computeGCD(num, gcd)
            if gcd == 1:
                gcd = num
                count += 1
        
        return count