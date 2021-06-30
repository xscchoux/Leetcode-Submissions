class Solution(object):
    def isArmstrong(self, n):
        """
        :type n: int
        :rtype: bool
        """
        res = 0
        
        k = math.log(n,10)//1 + 1

        tmp = n
        
        while tmp > 0:
            digit = tmp%10
            res += digit**k
            tmp//=10
            
        return res == n
        