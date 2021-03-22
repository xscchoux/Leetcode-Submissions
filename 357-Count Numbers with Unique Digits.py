class Solution(object):
    def countNumbersWithUniqueDigits(self, n):
        """
        :type n: int
        :rtype: int
        """
        def permutation(n):
            res = 1
            multiply = 9
            while n > 0:
                res *= multiply
                multiply -= 1
                n-=1
            return res
        
        def count(n):
            if n == 0:
                return 1
            return 9*permutation(n-1) + count(n-1)
        
        return count(n)