class Solution:
    def maxValue(self, n: int, index: int, maxSum: int) -> int:
        
# https://www.youtube.com/watch?v=TmB1IuJus4w
        def check(h):
            res = 0
            # left
            if h > index:
                res += (h + h - index)*(index+1)//2
            else:
                res += (h+1)*h//2
                res += (index+1) - h
            
            # right
            if n - index <= h:
                res += (h + h-(n-index)+1)*(n-index)//2
            else:
                res += (h+1)*h//2
                res += (n-index) - h
            return res - h
        
        left, right = 1, maxSum
        
        while left + 1 < right:
            mid = left + (right-left)//2
            if check(mid) > maxSum:
                right = mid
            else:
                left = mid
        
        if check(right) <= maxSum:
            return right
        else:
            return left