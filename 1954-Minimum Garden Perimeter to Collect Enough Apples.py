class Solution(object):
    def minimumPerimeter(self, neededApples):
        """
        :type neededApples: int
        :rtype: int
        """
# 12n^2 apples in a square with side length 2n
# 2n(n+1)(2n+1) apples "within" a square with side length 2n
        
        def perimeterVScount(n):
            return 2*n*(n+1)*(2*n+1)
        
        left, right = 1, 10**7   # 12n^2 >= 10^15, so we choose n = 10^7
        
        while left + 1 < right:
            mid = left + (right-left)//2
            if perimeterVScount(mid) >= neededApples:
                right = mid
            else:
                left = mid
        
        if perimeterVScount(left) >= neededApples:
            return 8*left
        else:
            return 8*right