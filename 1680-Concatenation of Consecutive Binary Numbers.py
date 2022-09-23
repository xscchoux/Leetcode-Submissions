class Solution(object):
    def concatenatedBinary(self, n):
        """
        :type n: int
        :rtype: int
        """
        kMod = 1000000007
        res = 1
        power = 1
        
        for i in range(2, n+1):
            if i&(i-1) == 0:
                power += 1
            res = ((res << power) | i)%kMod
        
        return res