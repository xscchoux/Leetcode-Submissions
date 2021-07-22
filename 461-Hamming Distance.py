class Solution(object):
    def hammingDistance(self, x, y):
        """
        :type x: int
        :type y: int
        :rtype: int
        """
# bit shift
        return bin(x^y).count('1')
        
# Brian Kernighan's Algorithm
        res = 0
        xor = x^y
        while xor:
            xor &=(xor-1)
            res += 1
        
        return res