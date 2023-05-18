class Solution:
    def findNthDigit(self, n: int) -> int:
    # O(logN)
        digits = base = 1
        
        while n > 9*base*digits:
            n -= 9*base*digits
            digits += 1
            base *= 10
            
        q, r = divmod(n-1, digits)
        
        return int(str(base + q)[r])