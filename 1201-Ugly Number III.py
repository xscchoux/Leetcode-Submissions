class Solution(object):
    def nthUglyNumber(self, n, a, b, c):
        """
        :type n: int
        :type a: int
        :type b: int
        :type c: int
        :rtype: int
        """
        def gcd(n1, n2):
            if n1 == 0:
                return n2            
            return gcd(n2%n1, n1)
        
        def lcm(n1, n2):
            return n1*n2/gcd(n1, n2)
        
        lcmAB = lcm(a,b)
        lcmBC = lcm(b,c)
        lcmAC = lcm(a,c)
        lcmABC = lcm(a, lcmBC)
        
        right = 2*10**9
        left = 1
        
        while left + 1 < right:
            mid = left + (right-left)//2
            k = mid//a + mid//b + mid//c - mid//lcmAB - mid//lcmBC - mid//lcmAC + mid//lcmABC
            if k >= n:
                right = mid
            else:
                left = mid
        
        if left//a + left//b + left//c - left//lcmAB - left//lcmBC - left//lcmAC + left//lcmABC == n:
            return left
        return right