import math
class Solution:
    def minimizeSet(self, divisor1: int, divisor2: int, uniqueCnt1: int, uniqueCnt2: int) -> int:
        lcm = math.lcm(divisor1, divisor2)
        left, right = 2, 3*10**9

        def notEnough(mx):
            a = mx - mx//divisor1
            b = mx - mx//divisor2
            c = mx - mx//divisor1 - mx//divisor2 + mx//lcm
            if a < uniqueCnt1:
                return True
            if b < uniqueCnt2:
                return True
            if a+b-c < uniqueCnt1+uniqueCnt2:
                return True
            return False
        
        while left + 1 < right:
            mid = left + (right-left)//2
            if not notEnough(mid):
                right = mid
            else:
                left = mid

        if not notEnough(left):
            return left
        else:
            return right