class Solution:
    def isReachableAtTime(self, sx: int, sy: int, fx: int, fy: int, t: int) -> bool:
        minStep = max(abs(sx-fx), abs(sy-fy))
        
        # sx == fx and sy == fy
        if minStep == 0:
            return False if t == 1 else True
        else:
            return minStep <= t