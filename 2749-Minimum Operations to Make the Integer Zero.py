class Solution:
    def makeTheIntegerZero(self, num1: int, num2: int) -> int:
        # num1 - k*num2 = 2^i1 + 2^i2 +...., where i1 + i2 +... <=k
        # Also, k should not be greater than num1-k*num2, or it is impossible to sum up to num1-k*num2 using k*2^0
        # The maximum value of k is 36, see this post: https://leetcode.com/problems/minimum-operations-to-make-the-integer-zero/discuss/3681390/it's-36-not-60-iterations
        
        for k in range(37):
            num = num1 - k*num2
            if num < 0:
                break
            if num.bit_count() <= k and k <= num:
                return k
            
        return -1