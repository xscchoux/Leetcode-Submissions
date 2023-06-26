class Solution:
    def longestString(self, x: int, y: int, z: int) -> int:
        if x == y:
            tot = 2*2*x
        else:
            mn = min(x, y)
            tot = 2*(mn + mn + 1)
        
        return tot + 2*z