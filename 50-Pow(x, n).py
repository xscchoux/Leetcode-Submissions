class Solution(object):
    def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """
        if n<0:
            return 1/self.myPow(x, -n)
        if n == 0:
            return 1
        if n == 1:
            return x
        half = self.myPow(x, n//2)
        
        if n%2 == 0:
            return half*half
        else:
            return half*half*x


        posN = True
        if n < 0:
            posN = False
            n = -n
        
# second visitd
        @cache
        def dfs(n):
            if n == 0:
                return 1
            if n%2 == 0:
                return dfs(n//2)*dfs(n//2)
            else:
                return dfs(n//2)*dfs(n//2)*x
            
        return dfs(n) if posN else 1/dfs(n)